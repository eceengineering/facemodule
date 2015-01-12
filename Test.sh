#!/bin/bash -e
echo "-------------------------------------------------------------------"
echo " THIS IS A TEST APPLICATION IMPLEMENTED FOR FACEMODULE " 
echo " SIMPLE FACE DETECTION !"
echo " ASSUMPTIONS:"
echo "	- Camera able to capture YUV (YUYV) format,"
echo "	- Face Module detects faces on the screen."
echo "	- To check your camera, please see CAMMODULE_TEST in github."
echo "-------------------------------------------------------------------"

sudo ./armTestApp
