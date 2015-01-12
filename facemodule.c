/* ============================================================================
 * @File: 	 facemodule.c
 * @Author: 	 Ozgur Eralp [ozgur.eralp@outlook.com]
 * @Description: FACEMODULE - Face Detection Module using Haar Cascades.
 *
 * ============================================================================
 *
 * Copyright 2014 Ozgur Eralp.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <linux/fb.h>
#include <asm/errno.h>
#include "facemodule.h"

static CvHaarClassifierCascade 	*cascade;
static CvMemStorage            	*storage;
static IplImage			*frame;

/* ============================================================================
 * @Function: facemodule_init
 * @Description: Initialize FACEMODULE.
 * ============================================================================
 */
int facemodule_init 	(struct facemodule_arguments *arg)
{
	int width = (arg->width);
	int height = (arg->height);
	char *file = "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml";

	cascade = (CvHaarClassifierCascade*) cvLoad (file, 0, 0, 0);
	if (!cascade)
	{
		printf("Could not load classifier cascade file!\n");
    		return 1;
	}
	storage = cvCreateMemStorage(0);
	frame = cvCreateImage( cvSize(width,height), IPL_DEPTH_8U, 4);

	return 0;
}

/* ============================================================================
 * @Function: 	 facemodule_close
 * @Description: Close FACEMODULE interface.
 * ============================================================================
 */
int facemodule_close	(void)
{
	printf("..facemodule will be closed! \n");
	
	cvReleaseHaarClassifierCascade(&cascade);
    	cvReleaseMemStorage(&storage);

	return 0;
}

/* ============================================================================
 * @Function: 	 facemodule_data
 * @Description: Feed FACEMODULE data.
 * ============================================================================
 */
int facemodule_data	(char *data)
{
	frame->imageData = data;
	
	//CvCapture *capture = 0;
	//capture = cvCaptureFromCAM( 0 );
	//frame = cvQueryFrame(capture);

	cvNamedWindow("image", CV_WINDOW_AUTOSIZE);
	cvShowImage("image", frame);
	cvWaitKey(1000);
	cvDestroyWindow("image");

	//cvReleaseCapture( &capture );

	return 0;
}

/* ============================================================================
 * @Function: 	 facemodule_detect
 * @Description: Detect face(s) in the frame.
 * ============================================================================
 */
int facemodule_detect	(void *result)
{
	CvSeq *faces = cvHaarDetectObjects(
                                       frame,
                                       cascade,
                                       storage,
                                       1.2,
                                       2, 0,
                                       cvSize(50, 50),
                                       cvSize(100, 100)
                                       );
    
  	printf("face detection result: (%d)...\n", faces->total);
	result = (void *)faces;

	for(int i = 0 ; i < (faces ? faces->total : 0) ; i++) {
		CvRect *r = (CvRect*)cvGetSeqElem(faces, i);
		printf("face: (%d, %d)\n", r->x, r->y);
	}

	return 0;
}

