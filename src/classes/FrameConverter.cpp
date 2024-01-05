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

    /**
     * https://microsoft.github.io/Azure-Kinect-Sensor-SDK/master/group___enumerations_gabc7cab5e5396130f97b8ab392443c7b8.html#gabc7cab5e5396130f97b8ab392443c7b8
    */
    switch (config.color_resolution)
    {
    case K4A_COLOR_RESOLUTION_OFF:
        std::cout << "Color Image was turned off for this recording, so resolution is: 0 x 0 pixels" << std::endl;
        this->_colorResolution[0] = 0;
        this->_colorResolution[1] = 0;
        break;
    case K4A_COLOR_RESOLUTION_720P:
        std::cout << "Color Image is 720P, so resolution is: 1280 x 720 16:9 pixels" << std::endl;
        this->_colorResolution[0] = 1280;
        this->_colorResolution[1] = 720;
        break;
    case K4A_COLOR_RESOLUTION_1080P:
        std::cout << "Color Image is 1080P, so resolution is: 1920 x 1080 16:9 pixels" << std::endl;
        this->_colorResolution[0] = 1920;
        this->_colorResolution[1] = 1080;
        break;
    case K4A_COLOR_RESOLUTION_1440P:
        std::cout << "Color Image is 1440P, so resolution is: 2560 x 1440 16:9 pixels" << std::endl;
        this->_colorResolution[0] = 2560;
        this->_colorResolution[1] = 1440;
        break;
    case K4A_COLOR_RESOLUTION_1536P:
        std::cout << "Color Image is 1536P, so resolution is: 2048 x 1536 4:3 pixels" << std::endl;
        this->_colorResolution[0] = 2048;
        this->_colorResolution[1] = 1536;
        break;
    case K4A_COLOR_RESOLUTION_2160P:
        std::cout << "Color Image is 2160P, so resolution is: 3840 x 2160 16:9 pixels" << std::endl;
        this->_colorResolution[0] = 3840;
        this->_colorResolution[1] = 2160;
        break;
    case K4A_COLOR_RESOLUTION_3072P:
    default:
        this->_colorResolution[0] = 4096;
        this->_colorResolution[1] = 3072;
        std::cout << "Color Image is 3072P, so resolution is: 4096 x 3072 4:3 pixels" << std::endl;
        break;
    }


    /**
     * https://microsoft.github.io/Azure-Kinect-Sensor-SDK/master/group___enumerations_ga3507ee60c1ffe1909096e2080dd2a05d.html#ga3507ee60c1ffe1909096e2080dd2a05d
    */
    switch (config.depth_mode)
    {
    case K4A_DEPTH_MODE_OFF:
        std::cout << "Depth Image was turned off for this recording, so resolution is: 0 x 0 pixels" << std::endl;
        this->_depthResolution[0] = 0;
        this->_depthResolution[1] = 0;
        break;
    case K4A_DEPTH_MODE_NFOV_2X2BINNED:
        std::cout << "Depth Image is NFOV_2X2BINNED, so resolution is: 320 x 288 pixels" << std::endl;
        this->_depthResolution[0] = 320;
        this->_depthResolution[1] = 288;
        break;
    case K4A_DEPTH_MODE_NFOV_UNBINNED:
        std::cout << "Depth Image is NFOV_UNBINNED, so resolution is: 640 x 576 pixels" << std::endl;
        this->_depthResolution[0] = 640;
        this->_depthResolution[1] = 576;
        break;
    case K4A_DEPTH_MODE_WFOV_2X2BINNED:
        std::cout << "Depth Image is WFOV_2X2BINNED, so resolution is: 512 x 512 pixels" << std::endl;
        this->_depthResolution[0] = 512;
        this->_depthResolution[1] = 512;
        break;
    case K4A_DEPTH_MODE_WFOV_UNBINNED:
        std::cout << "Depth Image is WFOV_UNBINNED, so resolution is: 1024 x 1024 pixels" << std::endl;
        this->_depthResolution[0] = 1024;
        this->_depthResolution[1] = 1024;
        break;
    case K4A_DEPTH_MODE_PASSIVE_IR:
    default:
        this->_depthResolution[0] = 0;
        this->_depthResolution[1] = 0;
        std::cout << "Depth Image is PASSIVE_IR, so no depth and hence resolution is: 0 x 0 pixels" << std::endl;
        break;
    }

    /**
     * https://microsoft.github.io/Azure-Kinect-Sensor-SDK/master/group___enumerations_gae2db1036e50e7a16aeef402a441fbdd9.html#gae2db1036e50e7a16aeef402a441fbdd9
    */
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

    std::experimental::filesystem::create_directories(rgbPath.parent_path());
    std::experimental::filesystem::create_directories(depthPath.parent_path());

    try
    {
        if (fr->isValidFrame && fr->rgb && fr->depth && fr->alignedImage)
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

            cv::imwrite(rgbPath.c_str(), rgbMat);
            cv::imwrite(depthPath.c_str(), depthMat);

            rgbMat.release();
            depthMat.release();
            rgbMat.deallocate();
            depthMat.deallocate();
        }
        else{
            int width = (this->_format == RGB_TO_DEPTH) ? this->_depthResolution[0] : this->_colorResolution[0];
            int height = (this->_format == RGB_TO_DEPTH) ? this->_depthResolution[1] : this->_colorResolution[1];

            rgbMat = cv::Mat::zeros(cv::Size2i(width, height), CV_32FC4);
            depthMat = cv::Mat::zeros(cv::Size2i(width, height), CV_32FC1);
            
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
    unsigned int dropped_frames = 0;
    std::experimental::filesystem::path rgbPath;
    std::experimental::filesystem::path depthPath;
    k4a_playback_t handle = this->_getHandle();
    FrameAligner faimgs = FrameAligner(handle);
    FrameResult *resultPTR = faimgs.getAlignedFrame(handle, this->_format, false);
    ProgressBar p(this->_totalFrames - 1, 10, "#");

    uint pathLength = this->_mkvPath.length();
    std::string subpath = "..."+this->_mkvPath.substr(pathLength-10, pathLength-1);

    p.setHeader("Extract and align: {" + subpath + "} ");
    while (resultPTR->hasNextFrame == K4A_STREAM_RESULT_SUCCEEDED)
    {
        std::stringstream footer;
        if (!resultPTR->isValidFrame)
        {
            dropped_frames += 1;
        }
        this->_save(resultPTR);

        rgbPath = this->_getFileName(this->_rgbDirectory, resultPTR->nextFrameIndex(), this->_prefixRGB, this->_suffixRGB);
        depthPath = this->_getFileName(this->_depthDirectory, resultPTR->nextFrameIndex(), this->_prefixDEPTH, this->_suffixDEPTH);
        resultPTR = faimgs.getAlignedFrame(handle, this->_format, this->_fileExists(rgbPath) && this->_fileExists(depthPath));

        footer << "[Extracted : <" << resultPTR->frameIndex << "/" << this->_totalFrames << ">, Dropped: <" << std::to_string(dropped_frames)<< "/" << this->_totalFrames << ">]";
        p.setFooter(footer.str());
        p.update(resultPTR->frameIndex);
        if (resultPTR->hasNextFrame == K4A_STREAM_RESULT_EOF || resultPTR->nextFrameIndex() >= this->_totalFrames)
        {
            break;
        }
        // std::cout << resultPTR->hasNextFrame << std::endl;
        // if(resultPTR->isValidFrame && (resultPTR->frameIndex >= 5)){//For debugging purposes only
        //     break;
        // }
    }
    p.finish();
    std::cout << "FINISHED PROCSESING ALL FRAMES " << std::endl;
    k4a_playback_close(handle);
}
