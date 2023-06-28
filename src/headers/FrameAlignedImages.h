#ifndef FRAMEALIGNEDIMAGES_H
#define FRAMEALIGNEDIMAGES_H

#include<k4a/k4a.h>
#include<k4arecord/playback.h>

struct FrameResult
{
    k4a_image_t rgb;
    k4a_image_t depth;
    k4a_stream_result_t status;
};

class FrameAlignedImages{
    private:
        FrameResult* _frameResult;
        k4a_playback_t _handle;
    public:
        FrameAlignedImages(k4a_playback_t handle);
        FrameResult* getFrame(k4a_playback_t handle);
};

#endif