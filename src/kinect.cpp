#include<iostream>
#include<string>
#include<algorithm>

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
        .required = true
        });

    const auto depthDirectory = p.add(argparse::Config<std::string>{ 
        .default_value = "./DEPTH",
        .allowed_values = {},
        .name = "depthdir",
        .help = "Directory where the depth frames are exported",
        .required = false
        });        
    const auto rgbDirectory = p.add(argparse::Config<std::string>{ 
        .default_value = "./RGB",
        .allowed_values = {},
        .name = "rgbdir",
        .help = "Directory where the rgb frames are exported",
        .required = false
        });

    const auto format = p.add(argparse::Config<unsigned int>{ 
        .default_value = RGB_TO_DEPTH,
        .allowed_values = {DEPTH_TO_RGB, RGB_TO_DEPTH},
        .name = "format",
        .help = "Extract and spatially align either depth to rgb, or rgb to depth",
        .required = false
        });
    const auto prefixRGB = p.add(argparse::Config<std::string>{ 
        .default_value = "",
        .allowed_values = {},
        .name = "prefixrgb",
        .help = "The prefix to add for the rgb frame images when saved",
        .required = false
        });
    const auto suffixRGB = p.add(argparse::Config<std::string>{ 
        .default_value = "-RGB",
        .allowed_values = {},
        .name = "suffixrgb",
        .help = "The suffix to add for the rgb frame images when saved",
        .required = false
        });
    
    const auto prefixDEPTH = p.add(argparse::Config<std::string>{ 
        .default_value = "",
        .allowed_values = {},
        .name = "prefixdepth",
        .help = "The prefix to add for the depth frame images when saved",
        .required = false
        });
    const auto suffixDEPTH = p.add(argparse::Config<std::string>{ 
        .default_value = "-DEPTH",
        .allowed_values = {},
        .name = "suffixdepth",
        .help = "The suffix to add for the depth frame images when saved",
        .required = false
        });

    const auto leading = p.add(argparse::Config<unsigned int>{ 
        .default_value = 4,
        .allowed_values = {},
        .name = "leading",
        .help = "The number of leading zeros to add with frame number when saving",
        .required = false
        });
    const auto &remaining_arguments = p.parse(argc, argv);

    FrameConverter f;
    
    assert(mkvPath);
    
    f.setVideoPath(mkvPath->value());
    f.setFileNameConventions(
        leading->value(), 
        rgbDirectory->value(), depthDirectory->value(),
        prefixRGB->value(), suffixRGB->value(), 
        prefixDEPTH->value(), suffixDEPTH->value()
        );

    f.setAlignmentFormat(format->value());
    f.extract();
    
    return 0;
};