# facemodule
Purpose of the face detection module (aka FACEMODULE) is to provide a basic baseline showing how east it is to perform face detection in an embedded device where a camera is attached.

This module has been designed for embedded Linux devices. The module runs at the user space.

Prerequirements

The module requires OpenCV installed in the working environment. OpenCV (Open Source Computer Vision Library: http://opencv.org) is an open-source BSD-licensed library that includes several hundreds of computer vision algorithms. 

Details:

A test application has been implemented by using FACEMODULE and CAMMODULE generated by ECE Engineering. The FACEMODULE outputs number of faces detected and their corrdinations in two-dimensional surface. The source codes are available in GitHub and open to everyone interested.

    Programming Language:   C
    Compiler:               GCC
    Test Platform(s):       ARM Cortex-A8 h/w
                            ARM Cortex-A9 h/w
    Test OS:                Linux Ubuntu
                            Linux Debian

  CAMMODULE Details: https://github.com/eceengineering/cammodule
  
  Input
  
    - Initialization parameters
    - Video frame data
    - See facemodule.h
    
  Output
  
    - The number of faces detected.
    - Coordinate (X,Y) of each face.
    
  Sequence
  
    Init()      - To initialize the module 
    SetData()   - To provide frame to the module
    FaceDetect()  - To run the algorithm
    Close()     - To close the module	
  
  Source Code Repo Link: https://github.com/eceengineering/rtspmodule

  How to Build and Run:
  
    Build:$make
    Run:  $./Test.sh
    
  Note:
  
  If you are worried about the camera in use, please check https://github.com/eceengineering/cammodule_test .
