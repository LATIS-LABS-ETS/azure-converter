#include<iostream>
#include<stdexcept>

#include<FrameConverter.h>
#include<FrameAlignedImages.h>
#include<FRAMECONVERTER_CONSTANTS.h>



FrameConverter::FrameConverter(){
    
};

k4a_playback_t FrameConverter::_getHandle(){
    k4a_playback_t handle = NULL;
    if (k4a_playback_open(this->_mkvPath.c_str(), &handle) != K4A_RESULT_SUCCEEDED)
    {
        std::string message = "Failed to open recording: " + this->_mkvPath;
        throw std::invalid_argument(message);
    }

    uint64_t recording_length = k4a_playback_get_recording_length_usec(handle);    
    printf("Recording is %lld seconds long\n", (long long int)(recording_length / 1000000));
    return handle;
}



void FrameConverter::extract(){ 
    k4a_playback_t handle = this->_getHandle();
    FrameAlignedImages faimgs = FrameAlignedImages(handle);
    FrameResult* resultPTR = faimgs.getFrame(handle);    
    std::cout << "THE RESULT OF FRAME READING(SUCCESS) ::: " << K4A_STREAM_RESULT_SUCCEEDED << std::endl;
    std::cout << "THE RESULT OF FRAME READING(FAILURE) ::: " << K4A_STREAM_RESULT_FAILED << std::endl;
    std::cout << "THE RESULT OF FRAME READING(End of File) ::: " << K4A_STREAM_RESULT_EOF << std::endl;
    std::cout << "CURRENT RESULT ::: " << resultPTR->status << std::endl;
    k4a_playback_close(handle);
}

void FrameConverter::setVideoPath(const std::string mkvPath){
    this->_mkvPath = mkvPath;
};

void FrameConverter::setAlignmentFormat(const unsigned int format){
    this->_format = format;
}

int FrameConverter::getAlignmentFormat(){
    return this->_format;
}

std::string FrameConverter::getVideoPath(){
    return this->_mkvPath;
}



