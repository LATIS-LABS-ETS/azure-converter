// #include<sys/stat.h>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#include <k4a_util.h>
#include <FRAMECONVERTER_CONSTANTS.h>
#include <ProgressBar.h>
#include <FrameConverter.h>

FrameConverter::FrameConverter(){

};

k4a_playback_t FrameConverter::_getHandle()
{
    k4a_playback_t handle = NULL;
    if (k4a_playback_open(this->_mkvPath.c_str(), &handle) != K4A_RESULT_SUCCEEDED)
    {
        std::string message = "Failed to open recording: " + this->_mkvPath;
        throw std::invalid_argument(message);
    }

    uint64_t recording_length = k4a_playback_get_recording_length_usec(handle);
    long long int totalSeconds = (long long int)(recording_length / 1000000);
    k4a_record_configuration_t config;
    k4a_calibration_t calibration;

    k4a_playback_get_record_configuration(handle, &config);
    k4a_playback_get_calibration(handle, &calibration);
    k4a_calibration_intrinsics_t intrinsics = calibration.depth_camera_calibration.intrinsics;

    std::cout << "(fx, fy)" << intrinsics.parameters.param.fx << ", " << intrinsics.parameters.param.fy << std::endl;
    std::cout << "(cx, cy)" << intrinsics.parameters.param.cx << ", " << intrinsics.parameters.param.cy << std::endl;   
    
    
    switch (config.camera_fps)
    {
        case K4A_FRAMES_PER_SECOND_5:
            this->_totalFrames = 5 * totalSeconds;
            std::cout << "FPS = 5" << std::endl;
            break;
        case K4A_FRAMES_PER_SECOND_15:
            this->_totalFrames = 15 * totalSeconds;
            std::cout << "FPS = 15" << std::endl;
            break;
        case K4A_FRAMES_PER_SECOND_30:
        default:
            this->_totalFrames = 30 * totalSeconds;
            std::cout << "FPS = 30" << std::endl;
            break;
    }
    printf("Recording is %lld seconds long\n", totalSeconds);
    std::cout << "TOTAL FRAMES IN THIS VIDEO :" << this->_totalFrames << std::endl;
    return handle;
}

std::experimental::filesystem::path FrameConverter::_getFileName(const std::string directory, const unsigned int frameIndex, const std::string prefix, const std::string suffix)
{
    std::string filename = std::to_string(frameIndex);
    unsigned int fill = std::max(0, (int)(this->_leading - filename.length()));

    std::string fullFilePath = "";
    std::experimental::filesystem::path dirPath = std::experimental::filesystem::path(directory);

    filename.insert(0, fill, '0');
    filename.insert(0, prefix);
    filename.insert(filename.length(), suffix);
    filename.insert(filename.length(), ".png");

    fullFilePath = dirPath / filename;

    return fullFilePath;
}

bool FrameConverter::_fileExists(std::experimental::filesystem::path name)
{
    //   struct stat buffer;
    //   return (stat (name.c_str(), &buffer) == 0);
    return std::experimental::filesystem::exists(name);
}

void FrameConverter::_save(FrameResult *fr)
{
    cv::Mat rgbMat;
    cv::Mat depthMat;

    std::experimental::filesystem::path rgbPath = this->_getFileName(this->_rgbDirectory, fr->frameIndex, this->_prefixRGB, this->_suffixRGB);
    std::experimental::filesystem::path depthPath = this->_getFileName(this->_depthDirectory, fr->frameIndex, this->_prefixDEPTH, this->_suffixDEPTH);
    try
    {
        if (fr->rgb && fr->depth && fr->alignedImage)
        {
            if (this->_format == RGB_TO_DEPTH)
            {
                rgbMat = k4a_get_mat(fr->alignedImage);
                depthMat = k4a_get_mat(fr->depth);
            }
            else if (this->_format == DEPTH_TO_RGB)
            {
                rgbMat = k4a_get_mat(fr->rgb);
                depthMat = k4a_get_mat(fr->alignedImage);
            }

            std::experimental::filesystem::create_directories(rgbPath.parent_path());
            std::experimental::filesystem::create_directories(depthPath.parent_path());

            cv::imwrite(rgbPath.c_str(), rgbMat);
            cv::imwrite(depthPath.c_str(), depthMat);

            rgbMat.release();
            depthMat.release();
            rgbMat.deallocate();
            depthMat.deallocate();
        }
    }
    catch (...)
    {
    }

    fr->release();
}

void FrameConverter::setVideoPath(const std::string mkvPath)
{
    this->_mkvPath = mkvPath;
};

void FrameConverter::setAlignmentFormat(const unsigned int format)
{
    this->_format = format;
}

unsigned int FrameConverter::getAlignmentFormat()
{
    return this->_format;
}

unsigned int FrameConverter::getTotalFrames()
{
    return this->_totalFrames;
}

std::string FrameConverter::getVideoPath()
{
    return this->_mkvPath;
}

void FrameConverter::setFileNameConventions(
    const unsigned int leading,
    std::string rgbDirectory, std::string depthDirectory,
    std::string prefixRGB, std::string suffixRGB,
    std::string prefixDEPTH, std::string suffixDEPTH)
{

    this->_leading = leading;

    this->_rgbDirectory = rgbDirectory;
    this->_depthDirectory = depthDirectory;

    this->_prefixRGB = prefixRGB;
    this->_suffixRGB = suffixRGB;

    this->_prefixDEPTH = prefixDEPTH;
    this->_suffixDEPTH = suffixDEPTH;
}

void FrameConverter::extract()
{
    std::experimental::filesystem::path rgbPath;
    std::experimental::filesystem::path depthPath;
    k4a_playback_t handle = this->_getHandle();
    FrameAligner faimgs = FrameAligner(handle);
    FrameResult *resultPTR = faimgs.getAlignedFrame(handle, this->_format, false);
    ProgressBar p = ProgressBar(this->_totalFrames, 50, "#");
    p.setHeaderAndFooter("Extraction and Alignment: " + this->_mkvPath, "So far, so good");
    while (resultPTR->hasNextFrame == K4A_STREAM_RESULT_SUCCEEDED)
    {
        if (resultPTR->isValidFrame)
        {
            this->_save(resultPTR);
        }
        rgbPath = this->_getFileName(this->_rgbDirectory, resultPTR->nextFrameIndex(), this->_prefixRGB, this->_suffixRGB);
        depthPath = this->_getFileName(this->_depthDirectory, resultPTR->nextFrameIndex(), this->_prefixDEPTH, this->_suffixDEPTH);
        resultPTR = faimgs.getAlignedFrame(handle, this->_format, this->_fileExists(rgbPath) && this->_fileExists(depthPath));
        p.update(resultPTR->frameIndex);
        if(resultPTR->hasNextFrame == K4A_STREAM_RESULT_EOF){
            break;
        }
        // if(resultPTR->isValidFrame && (resultPTR->frameIndex >= 5)){//For debugging purposes only
        //     break;
        // }
    }
    std::cout << "FINISHED PROCSESING ALL FRAMES " << std::endl;
    k4a_playback_close(handle);
}
