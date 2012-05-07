
#include "stdafx.h" //libs
#include<iostream>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

using namespace std;

CvHaarClassifierCascade *cascade_f; //classifiers to detect eyes and face.
CvHaarClassifierCascade *cascade_e;
CvMemStorage			*storage;

void detectEyes(IplImage *img); // three methods to detect eyes, face and a draw aim image over my eyes.
void drawImage(IplImage* target, IplImage* source, int x, int y);

IplImage * glasses = cvLoadImage("fire.jpg"); //load image of fire to be placed over my eyes!
IplImage *resized;


 
int main( int argc, char** argv )
{
   
    IplImage *img;
	CvCapture *capture;
	char *file1 = "haarcascade_frontalface_alt.xml"; //classifiers in a .xml file
    char *file2 = "haarcascade_eye.xml";
	int key = 1;
	capture = cvCaptureFromCAM( 0 ); // capture from webcam, inbuilt or via USB.

    // load the face classifier 
	cascade_f = (CvHaarClassifierCascade*)cvLoad(file1, 0, 0, 0);

    // load the eye classifier 
    cascade_e = (CvHaarClassifierCascade*)cvLoad(file2, 0, 0, 0);

    // setup memory storage, needed by the object detector 
    storage = cvCreateMemStorage(0);

	// check if files loaded poperly and memory is created
    assert(cascade_f && cascade_e && storage);

    cvNamedWindow("w");

    // detect eyes and display image

	while( key != 'q' ) {  //while the q key is not pressed...
       
        img = cvQueryFrame( capture ); //get a frame from capture, which stores data from the webcam
   if( !img ) break; //if there is no image, stop

    detectEyes(img); //method to detect eyes, see below
    cvShowImage("w", img); //show modified image with fire on top of eyes, see below

	  key = cvWaitKey(1); //wait for key press to continue, but if the parameter is positive, continue anyway. if q is pressed, program exits.
	}

    cvWaitKey(0); //wait for key press
    cvDestroyWindow("w"); //close windoes and release resoures
    cvReleaseImage(&img); //release memory used by the image

    return 0; // ALWAYS RETURN 0!
}

//methods


void drawImage(IplImage* target, IplImage* source, int x, int y) { //this method superimposes an image of fire over both the eyes.
    for (int ix=0; ix<source->width; ix++) {
        for (int iy=0; iy<source->height; iy++) { //loop through all pixels of the fire image

			
            int r = cvGet2D(source, iy, ix).val[2];
            int g = cvGet2D(source, iy, ix).val[1];
            int b = cvGet2D(source, iy, ix).val[0]; //get the rgb values.
			if(r!= 0 || g!= 0 || b != 0)
			{                            //the image that i am using has a black backround which I dont need, so I am not copying any black pixels, change this to suit your needs.
            CvScalar bgr = cvScalar(b, g, r); //create a new scalar value with the rgb of the pixel that is being currently processed.
            cvSet2D(target, iy+y, ix+x, bgr); //copy this image over the detected eyes at location (iy+y, ix+x) given to us by the detectEyes method.
			}
        }
    }
}




void detectEyes(IplImage *img) //method to detect eyes.
{
	int i;


	CvSeq *faces = cvHaarDetectObjects(  //using the face classifier, first detect the face.
		img, cascade_f, storage, 
		2.0, 3, 0, cvSize( 50,50 ) );

    //return if not found 
    if (faces->total == 0) return;

    // draw a rectangle on each face
	CvRect *r = (CvRect*)cvGetSeqElem(faces, 0);
	CvRect *g = (CvRect*)cvGetSeqElem(faces, 0);
	CvRect *e = (CvRect*)cvGetSeqElem(faces, 0);
	cvRectangle(img,
				cvPoint(e->x, e->y),
				cvPoint(e->x + e->width, e->y + e->height),
				CV_RGB(255, 0, 0), 1, 8, 0);
	


    //reset the memory buffer for the eyes now.
    cvClearMemStorage(storage);

    // Set the Region of Interest: estimate the eyes' position
    cvSetImageROI(img, cvRect(e->x, e->y + (e->height/5.5), e->width, e->height/3.0));

    // detect eyes using the eyes classifier
	CvSeq* eyes = cvHaarDetectObjects( 
        img, cascade_e, storage,
		1.15, 3, 0, cvSize(25, 15));

	//detect the two largest rects and say that they are eyes
	
	double area = 0.0;
	double pos1 = 0;
	double pos2 = 0;

		for( i = 0; i < (eyes ? eyes->total : 0); i++ ) 
		{
			r = (CvRect*)cvGetSeqElem( eyes, i );
			if(area < r->height*r->width && (r->x-e->x >30|| ((e->x+e->width)-(r->x+r->width)) > 30)) //see that it is more than 30px from the either edge of the face
			{
				area = r->height*r->width;
				pos1 = i;
			}
		}
		r = (CvRect*)cvGetSeqElem( eyes, pos1 ); //assign the largest eye found from list of all detetced eyes.
		area = 0.0;

			for( i = 0; i < (eyes ? eyes->total : 0); i++ ) //now find the second largest eye and see if it passes some logic
		{
			g = (CvRect*)cvGetSeqElem( eyes, i );
			if(area < g->height*g->width && i != pos1 && (g->x-e->x >30 || ((e->x+e->width)-(g->x+g->width)) > 30)) //see that it is more than 30px from the either edge of the face, and not the same as eye no 1.
			{
				if(abs(g->x-r->x)>20 && abs(g->y-r->y)< 7 )//now see that the distance between the eyes is more than 20px and the height differnece between them is less than 7px. 
					//due to checking for height difference, tilting the head will cuase the program to fail. Remove the line : abs(g->y-r->y)< 7 to allow tilting of the head, but the 
					//detection becomes considerably less accurate.
				{
				area = r->height*r->width; //store area and index to compare later with the other eyes.
				pos2 = i;
				}
			}
		}



    //Place fire on each eye.
	for( i = 0; i < (eyes ? eyes->total : 0); i++ ) {

		if(i == pos1 || i == pos2)//for all eyes detected, place fire on only the two eyes that passed the bave tests.
		{
		r = (CvRect*)cvGetSeqElem( eyes, i );
     IplImage *resized = cvCreateImage(cvSize(r->width , r->height),glasses->depth,glasses->nChannels );

cvResize(glasses, resized);
drawImage(img, resized, r->x, r->y);//drawimage expained above
		}

	}

    cvResetImageROI(img); //reset the region of interest.
	
	
}
