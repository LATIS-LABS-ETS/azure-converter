#ifndef FRAMECONVERTER_H
#define FRAMECONVERTER_H

#include<string>
#include <experimental/filesystem>
#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<k4a/k4a.h>
#include<k4arecord/playback.h>

#include<FRAMECONVERTER_CONSTANTS.h>
#include<FrameAlignedImages.h>

class FrameConverter{
    private:
        unsigned int _format = RGB_TO_DEPTH;
        unsigned int _leading;
        unsigned int _totalFrames = 0;

        std::string _mkvPath; 
        std::string _depthDirectory; 
        std::string _rgbDirectory; 

        std::string _prefixRGB;              
        std::string _suffixRGB;

        std::string _prefixDEPTH;              
        std::string _suffixDEPTH;

    private:
        k4a_playback_t _getHandle();
        void _save(FrameResult* fr);
        std::experimental::filesystem::path _getFileName(const std::string directory, const unsigned int frameIndex, const std::string prefix, const std::string suffix);
        bool _fileExists (std::experimental::filesystem::path name);

    public:
        FrameConverter();
        void setVideoPath(const std::string mkvPath);
        void setAlignmentFormat(const unsigned int format);
        void setFileNameConventions(
            const unsigned int leading, 
            std::string rgbDirectory, std::string depthDirectory, 
            std::string prefixRGB, std::string suffixRGB, 
            std::string prefixDEPTH, std::string suffixDEPTH);  
    
    public: 
        unsigned int getAlignmentFormat();
        unsigned int getTotalFrames();
        std::string getVideoPath();
    public:
        void extract();        
};
#endif