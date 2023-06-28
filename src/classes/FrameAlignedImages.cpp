#include<iostream>
#include<FrameAlignedImages.h>

FrameAlignedImages::FrameAlignedImages(k4a_playback_t handle){
    this->_handle = handle;
}

FrameResult* FrameAlignedImages::getFrame(k4a_playback_t handle){
    k4a_capture_t capture = NULL;
    k4a_stream_result_t result = k4a_playback_get_next_capture(handle, &capture);

    k4a_calibration_t calibration;
    k4a_result_t calibrationResult;

    k4a_transformation_t transformation = NULL;

    k4a_image_t rgb = NULL;
    k4a_image_t depth = NULL;

    if(result == K4A_STREAM_RESULT_SUCCEEDED){
        calibrationResult = k4a_playback_get_calibration(handle, &calibration);
        if(calibrationResult == K4A_RESULT_SUCCEEDED){
            transformation = k4a_transformation_create(&calibration);

            rgb = k4a_capture_get_color_image(capture);
            depth = k4a_capture_get_depth_image(capture);

            // printf(" | RGB res:%4dx%4d",
            //     k4a_image_get_height_pixels(rgb),
            //     k4a_image_get_width_pixels(rgb));
        }   
        
    }

    this->_frameResult->rgb = rgb;
    this->_frameResult->depth = depth;
    this->_frameResult->status = result;
    k4a_capture_release(capture);
    return this->_frameResult;
}