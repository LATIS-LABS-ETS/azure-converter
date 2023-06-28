#ifndef FRAMECONVERTER_H
#define FRAMECONVERTER_H

#include<string>
#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<k4a/k4a.h>
#include<k4arecord/playback.h>

#include<FRAMECONVERTER_CONSTANTS.h>

class FrameConverter{
    private:
        unsigned int _format = RGB_TO_DEPTH;
        std::string _mkvPath;              
    private:
        k4a_playback_t _getHandle();
    public:
        FrameConverter();
        void setVideoPath(const std::string mkvPath);
        void setAlignmentFormat(const unsigned int format);
        void extract();
    
    public: 
        int getAlignmentFormat();
        std::string getVideoPath();
};

#endif