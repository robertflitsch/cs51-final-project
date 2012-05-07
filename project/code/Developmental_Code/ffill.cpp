/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * ffill.cpp
 *
 * Bobby Flitsch
 * Aaron Graham-Horowitz
 * TJ Barber
 * Hikari Senju
 *
 * CS51 Final Project
 *
 * This program was used to understand how cv::floodFill works, and exactly
 * what arguments should be passed to the function in order to make it work
 * in the behavior we intended. Using the "floodFillDemo.cpp" program
 * (provided by OpenCV) on "eye.bmp", we were able to figure out a pixel on
 * the pupil of the eye was located at Point(150,170). Since this program was
 * used before we correctly figured out the method for looping through an
 * image and search for a pixel to use as the seed to cv::floodFill, the
 * previously stated point has been hard coded into this file, as its intended
 * use is merely to experiment with the intended behavior of our calls to
 * cv::floodFill within our eyedetect program.
 *
 * The intended behavior of the program (called with no command line args)
 * should be as follows:
 * 1) The eye image will be loaded and displayed in the "input" window. The
 *    program will wait for a key to be pressed before continuing.
 * 2) After a key is pressed, the input is copied to another image. floodFill
 *    is then called on this copied image, and the object (the filled in
 *    pupil) is stored as a rect "eye". A circle is then drawn on the
 *    *original* image (this way, the detected image does *not* have the
 *    flood filled area, just the drawn circle). The flood filled and circled
 *    images are then displayed.
 * 3) When a key is pressed, the windows are destroyed, and the program exits.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(void)
{
    /* create image path (default to eye.bmp since the seed is based off of
     * this specific image) */
    String path = "images/eye.bmp";
    
    // create original image
    Mat input = imread(path);

    // show original image
    cvNamedWindow( "input", 1 );
    imshow("input", input);
    waitKey();
    
    // initialize floodfill vars
    Mat fimg;
    Point seed = Point(150,170);
    Scalar color = CV_RGB(0,0,255);
    Rect eye;
    int lo = 20;
    int up = 20;
    int flags = CV_FLOODFILL_FIXED_RANGE;
    
    // copy the image that flood fill will overwrite
    input.copyTo(fimg);

    // run floodfill to locate eye object
    floodFill(fimg, seed, color, &eye, Scalar::all(lo),
              Scalar::all(up), flags);
    
    // initialize circle drawing vars     
    Point center;
    int radius;
    double scale = 1.0;
    Rect *r;
    
    // set r to point to the data for the eye rect
    r = &eye;
    
    // set the vals for drawing the circle              
    center.x = cvRound((r->x + r->width*0.5)*scale);
    center.y = cvRound((r->y + r->height*0.5)*scale);
    radius = cvRound((r->width + r->height)*0.25*scale);
    
    // draw the circle on original image
    circle(input, center, radius, color, -1, 8, 0);
        
    // show the 2 edited images
    cvNamedWindow( "ffilled", 1 );
    cvNamedWindow( "circled", 1 );
    imshow("ffilled", fimg);
    imshow("circled", input);
    
    // exit on key press
    waitKey();
    cvDestroyWindow("input");
    cvDestroyWindow("ffilled");
    cvDestroyWindow("circled");
    return 0;
}
