#ifndef FRAMEALIGNEDIMAGES_H
#define FRAMEALIGNEDIMAGES_H

#include<k4a/k4a.h>
#include<k4arecord/playback.h>

class ImageSet
{
    public:
        k4a_image_t rgb = NULL;
        k4a_image_t depth = NULL;
        k4a_calibration_t calibration;
        k4a_transformation_t transformation = NULL;
    public:
        ImageSet(){};
        ~ImageSet();
        void ensureRGBAsBGR32();
    private: 
        void _convertImage(k4a_image_t srcImage, k4a_image_t* copyToImagePTR, const unsigned int channels = 4);
};

class FrameResult: public ImageSet
{        
    public:
        k4a_image_t alignedImage = NULL;
        unsigned int frameIndex = 0;
        bool isValidFrame  = 0;
        k4a_stream_result_t hasNextFrame = K4A_STREAM_RESULT_SUCCEEDED;
    public:
        FrameResult() : ImageSet(), frameIndex(0) {};
        ~FrameResult();
        void alignImages(const unsigned int format);    
        void release(); 
        unsigned int nextFrameIndex();
};
class FrameAligner{
    private:
        FrameResult* _frameResult;
        k4a_playback_t _handle;
    private:
        void _capturedImageSet(k4a_playback_t handle, k4a_capture_t capture, FrameResult* is, const unsigned int format);

    public:
        FrameAligner(k4a_playback_t handle);
        ~FrameAligner(); 
        FrameResult* getAlignedFrame(k4a_playback_t handle, const unsigned int format, bool skipFrameProcessing);
};

#endif