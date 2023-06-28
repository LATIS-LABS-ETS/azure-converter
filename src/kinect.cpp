#include<iostream>
#include<argparse.h>
#include<FrameConverter.h>
#include<FRAMECONVERTER_CONSTANTS.h>

using namespace std;

int main(const int argc, const char* argv[]){

    argparse::Parser p("Azure Converter", "Extract, align and export RGB and DEPTH from MKV videos recorded using Kinect device");    
    const auto mkvPath = p.add(argparse::Config<std::string>{ 
        .default_value = "./video_path.mkv",
        .allowed_values = {},
        .name = "vpath",
        .help = "Path to the mkv file",
        .required = true,
        .letter = 'm',
        });
    const auto format = p.add(argparse::Config<unsigned int>{ 
        .default_value = RGB_TO_DEPTH,
        .allowed_values = {DEPTH_TO_RGB, RGB_TO_DEPTH},
        .name = "format",
        .help = "Extract and spatially align either depth to rgb, or rgb to depth",
        .required = false,
        .letter = 'f',
        });
    const auto &remaining_arguments = p.parse(argc, argv);

    FrameConverter f;
    
    assert(mkvPath);
    
    f.setVideoPath(mkvPath->value());
    f.setAlignmentFormat(format->value());

    f.extract();

    std::cout << remaining_arguments.size() << std::endl;
    // std::cout << f.getVideoPath() << std::endl;
    // std::cout << f.getAlignmentFormat() << std::endl;
    return 0;
};