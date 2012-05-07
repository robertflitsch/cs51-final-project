/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * looping.cpp
 *
 * Bobby Flitsch
 * Aaron Graham-Horowitz
 * TJ Barber
 * Hikari Senju
 *
 * CS51 Final Project
 *
 * This program was used to figure out how to loop through the pixels of an
 * IplImage successfully (please refer to "Also note please:" as to why
 * IplImages are being used for pixel iteration over cv::Mats). Like
 * "ffill.cpp," it was just used for testing iteration, to apply in the final
 * "eyedetect.cpp" file, so the image path (to eye.bmp) has been hard coded
 * in the file. The functionality of the program is as follows:
 *
 * 1) Upon running the program, it should load "eye.bmp" into a matrix and
 *    display the image as "input" in a window.
 *
 * 2) Once a key is pressed, the program will then run a black filter on the
 *    image, save it into the "black/" directory, (to be processed later as
 *    an IplImage) and then display the black image as "black image" in a
 *    window.
 *
 * 3) Once a key is pressed, the black filtered image is loaded as an
 *    IplImage, and a black background is loaded as a matrix (this image will
 *    be printed on to try and construct a copy of the black filtered image).
 *    The program then iterates through the black filtered image, printing a
 *    white, pixel sized circle on the black background every time a white
 *    pixel is found on the filtered image. The resulting image is displayed,
 *    until a key is pressed, whereupon the program exits.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat blackFilter(const Mat& src);
bool pixel_is_white (int red, int green, int blue);
Point point_of_pixel (int pixel, int width, int height);

int main(void)
{
    // default path to eye.bmp
    String name = "eye.bmp";
    String path = "images/" + name;
    
    // load Mat of input image
    Mat input = imread(path);
    
    // display input
    cvNamedWindow( "input", 1 );
    imshow("input", input);
    waitKey();
    
    // run black filter on Mat
    Mat blackOnly = blackFilter (input);
    
    // save the black image to be loaded as IplImage
    String blackPath = "black/" + name;
    if ( !imwrite( blackPath, blackOnly ) )
        cout << "Couldn't write " << blackPath << endl;
    
    // display black image
    cvNamedWindow( "black image", 1 );
    imshow("black image", blackOnly);
    waitKey();
    
    // load black image as IplImage
    const char *cBlackPath = blackPath.c_str();
    IplImage* img = cvLoadImage(cBlackPath, CV_LOAD_IMAGE_UNCHANGED);
    
    if (!img)
    {
        cout << "!!! cvLoadImage failed !!!" << endl;
        exit(1);
    }
    
    // load black background to print circles onto
    Mat black = imread("images/black.bmp");
    
    // initialize vars for iterating through IplImage
    int width = img->width; 
    int height = img->height;
    int bpp = img->nChannels;
    int red, green, blue;

    for (int i=0; i < width*height*bpp; i+=bpp) 
    {
        // set pixel color vals (0 if black, -1 if not)
        red = img->imageData[i];
        green = img->imageData[i+1];
        blue = img->imageData[i+2];
        
        // if the pixel registers as not black...
        if (pixel_is_white (red, green, blue))
        {
            // run pupil detection with this pixel as a seed
            Scalar color = CV_RGB(255,255,255);
            int radius = 1;
            Point center = point_of_pixel (i, width, height);
            circle( black, center, radius, color, -1, 8, 0 );            
        }
    }

    // release IplImage
    cvReleaseImage(&img);
    
    // display the result picture (compare it to the black image)
    cvNamedWindow( "result", 1 );
    imshow("result", black);
    waitKey();
    
    // on key press, destroy windows and exit
    cvDestroyWindow("input");
    cvDestroyWindow("black image");
    cvDestroyWindow("result");
    return 0;
}

/*
 * Function that takes an image and returns an image that has the dark pixels
 * painted white, and everything else painted black. Used to detect really
 * dark pixels on a file (pupil for instance)
 */

Mat blackFilter(const Mat& src)
{
    // make sure image is correct type
    assert(src.type() == CV_8UC3);

    // run the filter on the image
    Mat blackOnly;
    inRange(src, Scalar(0, 0, 0), Scalar(10, 10, 10), blackOnly);
    
    // returns image with black pixels as white and all others as black
    return blackOnly;
}

/*
 * Function that takes the pixel information for an IplImage, and returns true
 * if the image pixel is not black (on the blackOnly picture, this indicates
 * white).
 * Assume this function is only used on the blackOnly picture.
 */

bool pixel_is_white (int red, int green, int blue)
{
    bool check = red != 0 && green != 0 && blue != 0; 
    return check;   
}

/*
 * Takes a pixel number (within a certain width and height) and returns the
 * pixel's coordinate position within the image.
 */
Point point_of_pixel (int pixel, int width, int height)
{
    // initialize point vals
    int row;
    int col;
    
    // avoid divide by zero
    if (height != 0 && width != 0)
    {
        // compute point coordinates
        row = pixel/height;
        col = pixel%width;
    
        // return the resulting coordinates
        return Point(col, row);
    }
    
    // function called incorrectly
    else
    {
        cout << "Invalid parameters passed to \"point_of_pixel\" "
                "function" << endl;
        return Point(-1, -1);
    }
}
