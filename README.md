# azure-converter

A small c++ based application to extract and align RGBD images captured using Kinect Azure. 
This application uses the Kinect SDK for the purposes of aligning the frames spatially from the RGB to Depth or vice-versa.  

# Setup Instructions
This application is based on building your own docker image to use the kinect sdk which works only with Ubuntu 18.04. However, the default Ubuntu 18.04 image does not work due to unavailability of opengl capabilities. Hence, we need to build the docker image with the image provided by nvidia. 

Even after building the image there are certain steps necessary to ensure succesful running of this azure-converter application. 

## Build Instructions

### Docker
A tutorial on how to build the docker image it is better to refer to the [extensive docker tutorial](https://www.docker.com/101-tutorial/).
Once you have gained a good understanding of the docker ecosystem, go ahead and build the docker image inside the [folder Docker](./Docker/Dockerfile).
This image is built using the Ubuntu 18.04 image offered by nvidia as it is necessary. 

Personally, vscode is used for mounting and working with the docker image that is built using the provided docker script. 
This docker script ensures to install all opencv and kinect sdk libraries in the docker subsystem that is necessary to access the SDK and perform the task of spatial alignment of the modalities viz. DEPTH and RGB.

#### Caveat
Once the docker image has been built then it is not straightforward to just build the application and start using it.
You need to do the below two things everytime(after system restarts) you run this docker image
- ```docker run -it  --name=azuregl --privileged  -v /tmp/.X11-unix:/tmp/.X11-unix:rw -v /usr/lib/nvidia:/usr/lib/nvidia --device /dev/dri --rm -e __NV_PRIME_RENDER_OFFLOAD=1 -e __GLX_VENDOR_LIBRARY_NAME=nvidia -e DISPLAY=$DISPLAY  -e NVIDIA_VISIBLE_DEVICES=all -e NVIDIA_DRIVER_CAPABILITIES=all --gpus=all --name=carla-server --net=host -d nvidia-azure-env```
- ```xhost +Local:*``` 

Both the above commands are run in the context of your local machine on which this docker image is going to mounted. 
- The first command ensures that the docker image is run with necessary permissions and modules to ensure opengl capabilities so that Kinect SDK library referenced in this application can work smoothly.
- The second step ensures that the docker image has access to opengl calls by adding ```+Local``` to your ```xhost``` list.

BTW, you can find the above instructions inside the [DOCKER-Kinect-Headache](./Docker/DOCKER-Kinect-Headache) as well.
If you are asking why the name of the file contains the word Headache, then the answer is, it was exactly what happened when setting up this whole thing. 


### CMAKE
Once you have established the docker ecosystem the first step is to clone this repository on a location inside the docker system.
The next step is to run cmake for the provided [CMAKE file](./CMakeLists.txt) and generate the makefiles to a build directory of your choice.
In all probabilities this step should be completed sucessfully and the final step is to know on how to use this C++ application.

## Example usage

To use this application you need the mkv files exported after recording the video from your Kinect device. 
If your directory structure looks like as show below:

* azure-converter
    - argparse
    - <span style="color:green"><b>build</b></span>(The built binary file of this application)
    - <span style="color:orange"><b>captures</b></span> (Folder that contains your RGBD videos)
    - Docker
    - libraries
    - src
    - .gitignore
    - <span style="color:yellow"><b>batch_converter.sh</b></span>
    - CMakeLists.txt
    - README.md

Once the videos are ready and present inside the <span style="color:yellow"><b>batch_converter.sh</b></span> run the below command from the terminal at the location(```root@(yourusername):~azure_converter/```) to extract othe spatially aligned RGBD frames of that video:

```
./batch_converter.sh 1 (Extract frames and align Depth to RGB)
```
or 
```
./batch_converter.sh 2 (Extract frames and align RGB to Depth)
```
The above command specifies the direction of alignment between the RGB and D frames viz., should depth frame image scale to the resolution of RGB or RGB frame image scale to that of the depth.
However, the term scale is not to be taken literally rather it needs to understood that there is much more to alignment of RGB and D frames with each other as there would be loss of pixel values in either directions. 
Once the frames have been converted you will find folders with the name of the video files and inside each folder you will find two subdirectories namely RGB and DEPTH with the respective aligned frames for the two modalities. 
Should you encounter any issues please do not feel shy in posting an issue. 


# <ins>Merci et bonne chance</ins>