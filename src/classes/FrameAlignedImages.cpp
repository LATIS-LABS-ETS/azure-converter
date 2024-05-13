/**
 * Important links that made this code happen
 * https://github.com/microsoft/Azure-Kinect-Sensor-SDK/issues/1697
 * https://github.com/microsoft/Azure-Kinect-Sensor-SDK/issues/978#issuecomment-566002061
 * https://github.com/MarekKowalski/LiveScan3D/blob/AzureKinect/src/LiveScanClient/azureKinectCapture.cpp#L160
 * https://github.com/microsoft/Azure-Kinect-Sensor-SDK/issues/1482
 * https://github.com/microsoft/Azure-Kinect-Sensor-SDK/blob/develop/examples/transformation/main.cpp
 * https://learn.microsoft.com/en-us/azure/kinect-dk/record-playback-api#use-the-playback-api
 * https://learn.microsoft.com/en-us/azure/kinect-dk/use-image-transformation
 * https://microsoft.github.io/Azure-Kinect-Sensor-SDK/master/group___functions_gaf3a941f07bb0185cd7a72699a648fc29.html#gaf3a941f07bb0185cd7a72699a648fc29
 * https://microsoft.github.io/Azure-Kinect-Sensor-SDK/master/group___functions_ga343a129cd5dcff66788c737938e754b7.html#ga343a129cd5dcff66788c737938e754b7
 */
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include <FRAMECONVERTER_CONSTANTS.h>
#include <k4a_util.h>

#include <FrameAlignedImages.h>

void ImageSet::_convertImage(k4a_image_t srcImage, k4a_image_t *copyToImagePTR, const unsigned int channels)
{
    assert((srcImage !== nullptr) && "Error: k4a_image_t argument: 'srcImage' is null");
    cv::Mat cvImage = k4a_get_mat(srcImage);
    k4a_image_create(K4A_IMAGE_FORMAT_COLOR_BGRA32, cvImage.cols, cvImage.rows, cvImage.cols * channels * (int)sizeof(uint8_t), copyToImagePTR);
    uint8_t *k4a_img = k4a_image_get_buffer(*copyToImagePTR);
    memcpy(k4a_img, &cvImage.ptr<cv::Vec4b>(0)[0], cvImage.rows * cvImage.cols * sizeof(cv::Vec4b));
    cvImage.release();
    cvImage.deallocate();
}

void ImageSet::ensureRGBAsBGR32()
{
    k4a_image_format_t rgb_im_format, depth_im_format;
    k4a_image_t convertedRGB = nullptr, convertedDEPTH = nullptr;
    if (this->rgb != nullptr)
    {
        rgb_im_format = k4a_image_get_format(this->rgb);
        switch (rgb_im_format)
        {
        case K4A_IMAGE_FORMAT_COLOR_BGRA32:
            // std::cout<< "RGB IN GOOD FORMAT(BGRA32) NO CONVERSIONS NEEDED FOR THIS FRAME" << std::endl;
            break;
        default:
            // std::cout<< "RGB NOT IN GOOD FORMAT(BGRA32), SO CONVERT TO REQUIRED FORMAT" << std::endl;
            this->_convertImage(this->rgb, &convertedRGB, 4);
            this->rgb = convertedRGB;
        }
    }
    else
    {
        // std:: cout << "No VALID RGB FOUND " << std::endl;
    }

    if (this->rgb !=nullptr && this->depth !=nullptr)
    {
        depth_im_format = k4a_image_get_format(this->rgb);
        switch (depth_im_format)
        {
        case K4A_IMAGE_FORMAT_COLOR_BGRA32:
            // std::cout<< "DEPTH IN GOOD FORMAT(BGRA32) NO CONVERSIONS NEEDED FOR THIS FRAME" << std::endl;
            break;
        default:
            // std::cout<< "DEPTH NOT IN GOOD FORMAT(BGRA32), SO CONVERT TO REQUIRED FORMAT" << std::endl;
            this->_convertImage(this->depth, &convertedDEPTH, 1);
            this->depth = convertedDEPTH;
        }
    }
    else
    {
        // std:: cout << "No VALID DEPTH FOUND " << std::endl;
    }
};

ImageSet::~ImageSet(){
    this->rgb = nullptr;
    this->depth = nullptr;
    this->transformation = nullptr;

    delete this->rgb;
    delete this->depth;
    delete this->transformation;
}

FrameResult::~FrameResult(){
    this->alignedImage = nullptr;
    delete this->alignedImage;
}

void FrameResult::alignImages(const unsigned int format)
{
    unsigned int imWidth = 0, imHeight = 0;
    if (this->rgb != nullptr && this->depth != nullptr)
    {
        if (format == RGB_TO_DEPTH)
        {

            imWidth = k4a_image_get_width_pixels(this->depth);
            imHeight = k4a_image_get_height_pixels(this->depth);
            k4a_image_create(
                K4A_IMAGE_FORMAT_COLOR_BGRA32,
                imWidth,
                imHeight,
                imWidth * 4 * (int)sizeof(uint8_t),
                &this->alignedImage);
            k4a_transformation_color_image_to_depth_camera(this->transformation, this->depth, this->rgb, this->alignedImage);
        }
        if (format == DEPTH_TO_RGB)
        {
            imWidth = k4a_image_get_width_pixels(this->rgb);
            imHeight = k4a_image_get_height_pixels(this->rgb);
            k4a_image_create(
                K4A_IMAGE_FORMAT_DEPTH16,
                imWidth,
                imHeight,
                imWidth * (int)sizeof(uint16_t),
                &this->alignedImage);
            k4a_transformation_depth_image_to_color_camera(this->transformation, this->depth, this->alignedImage);
        }
    }
    else
    {
        std::string message = "";
        if (!this->rgb)
        {
            message = "No valid RGB data, hence cannot align RGB and DEPTH images";
        }
        if (!this->depth)
        {
            message += "\nNo valid DEPTH data, hence cannot align RGB and DEPTH images";
        }
        // std::cout << message << std::endl;
    }
}

void FrameResult::release()
{
    if (this->rgb != nullptr)
    {
        k4a_image_release(this->rgb);
        this->rgb = nullptr;
        delete this->rgb;
    }
    if (this->depth != nullptr)
    {
        k4a_image_release(this->depth);
        this->depth = nullptr;
        delete this->depth;
    }
    if (this->alignedImage != nullptr)
    {
        k4a_image_release(this->alignedImage);
        this->alignedImage = nullptr;
        delete this->alignedImage;
    }
    if (this->transformation != nullptr)
    {
        k4a_transformation_destroy(this->transformation);
        this->transformation = nullptr;
        delete this->transformation;
    }
    this->isValidFrame = false;
    this->rgb = nullptr;
    this->depth = nullptr;
    this->alignedImage = nullptr;
    this->transformation = nullptr;
}

unsigned int FrameResult::nextFrameIndex()
{
    return this->frameIndex + 1;
}

FrameAligner::FrameAligner(k4a_playback_t handle)
{
    this->_handle = handle;
    this->_frameResult = new FrameResult();
}

FrameAligner::~FrameAligner(){
    this->_frameResult = nullptr;
    delete this->_frameResult;
}

void FrameAligner::_capturedImageSet(k4a_playback_t handle, k4a_capture_t capture, FrameResult *is, const unsigned int format)
{
    k4a_result_t calibrationResult = k4a_playback_get_calibration(handle, &is->calibration);
    if (calibrationResult == K4A_RESULT_SUCCEEDED)
    {
        is->depth = k4a_capture_get_depth_image(capture);
        is->rgb = k4a_capture_get_color_image(capture);
        is->transformation = k4a_transformation_create(&is->calibration);
    }
    if(is->rgb != nullptr && is->depth != nullptr){
        is->ensureRGBAsBGR32();
        is->alignImages(format);
    }    
}

FrameResult *FrameAligner::getAlignedFrame(k4a_playback_t handle, const unsigned int format, bool skipFrameProcessing)
{
    assert((handle !== nullptr) && "Error: k4a_playback_t argument: 'handle' is null");
    k4a_capture_t capture = nullptr;
    k4a_stream_result_t result = k4a_playback_get_next_capture(handle, &capture);
    if (result == K4A_STREAM_RESULT_SUCCEEDED && !skipFrameProcessing)
    {
        this->_capturedImageSet(handle, capture, this->_frameResult, format);
    }
    else
    {
        if (capture)
        {
            k4a_capture_release(capture);
        }
        this->_frameResult->hasNextFrame = result;
        this->_frameResult->isValidFrame = true;
        this->_frameResult->frameIndex++;
        return this->_frameResult;
    }
    if (result == K4A_STREAM_RESULT_EOF)
    {
        std::cout << "END OF STREAM REACHED " << std::endl;
    }
    this->_frameResult->hasNextFrame = result;
    this->_frameResult->isValidFrame = (this->_frameResult->rgb != nullptr && this->_frameResult->depth != nullptr); // || skipFrameProcessing;
    this->_frameResult->frameIndex++;
    if (capture)
    {
        k4a_capture_release(capture);
    }
    else
    {
        this->_frameResult->isValidFrame = false;
    }
    return this->_frameResult;
}