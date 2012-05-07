/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * eyedetect.cpp
 *
 * Bobby Flitsch
 * Aaron Graham-Horowitz
 * TJ Barber
 * Hikari Senju
 *
 * CS51 Final Project
 *
 * This program runs eye detection on an image file by iterating through an
 * image's pixels and looking for specific pixel properties. The program
 * first loads the image from the path passed in at the command line,
 * creates a "black filtered" image, (an image where all the black pixels of
 * the input image are colored white, and anything else is colored black),
 * iterates over the black image to find a white pixel (indicating a possible
 * pupil), cv::floodFill over this to create a rect for the object, then draws
 * filled circles over the detected "eyes" and then saves it as an image file 
 * in the "eye_result" directory.
 *
 * Please note: All of this code was written by me (Bobby) except for some of 
 * the variable initialization within the "ffill" function, for which many of
 * the ideas and syntax were borrowed from the "floodFillDemo.cpp" program 
 * provided by OpenCV. As well, ideas for iterating through IplImages with
 * data pointers were frankensteined from various code snippets online that
 * pointed me in the direction of functions defined in the OpenCV
 * specification.
 *
 * Also note please: IplImages (although "obselete" in the latest versions of
 * OpenCV) were used because of the way they pass around pointers. Originally,
 * our functionality of iterating through the images used pointers to cv::Mat
 * data, however, it produced confusing errors and behavior we didn't 
 * understand. As such, it was necessary to supplement the iterating
 * functionality with IplImages, even though it means multiple data structures
 * for the same image (we still had to keep cv::Mats in the functionality
 * because some of the newer functions, like cv::floodFill, only take cv::Mats
 * as arguments, and not IplImages.
 *
 * Finally please note: This program is only meant to be called using the
 * "run_project.sh" bash script, in which the scale for "haardetect" is set to
 * 1.0. Therefore, it assumed to not be necessary to process the image with a
 * scale within this program.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

// prototype declarations
Mat blackFilter(const Mat& src);
bool pixel_is_white (int red, int green, int blue);
Point point_of_pixel (int pixel, int width, int height);
Mat ffill (Mat& input, Point seed);

int main(int argc, char** argv)
{
    // if not correct # argc, then function called incorrectly
    if (argc != 2)
    {
        cout << "Incorrect command line call. Please format "
                "your call to match the following:\n"
                "./eyedetect <image path>" << endl;
        return -1;
    }
    
    // process images
    else
    {
        // print that detection is starting
        cout << "Running eyedetect..." << endl;
    
        // get filename (construct path in const char* format)
        String name = argv[1];
        String path = "images/" + name;
        
        // load Mat of input image
        cout << "Loading input..." << endl;
        Mat input = imread(path);
        
        // run black filter on Mat
        cout << "Black filtering image..." << endl;
        Mat blackOnly = blackFilter (input);
        
        // save the black image to be loaded as IplImage
        cout << "Writing black image to folder..." << endl;
        String blackPath = "black/" + name;
        if ( !imwrite( blackPath, blackOnly ) )
            cout << "Couldn't write " << blackPath << endl;
        
        // load black image as IplImage
        cout << "Loading black image..." << endl;
        const char *cBlackPath = blackPath.c_str();
        IplImage* img = cvLoadImage(cBlackPath, CV_LOAD_IMAGE_UNCHANGED);
        
        // check for failed load
        if (!img)
        {
            cout << "!!! cvLoadImage failed !!!" << endl;
            exit(1);
        }
        
        // initialize vars for iterating through IplImage
        double t;
        int width = img->width; 
        int height = img->height;
        int bpp = img->nChannels;
        int red, green, blue;
        int num_eyes = 0;
        
        // check that if condition gets stepped into (for writing file)
        bool stepped = false;
    
        // initialize Mat for pupil detection
        Mat result;
    
        // begin detection
        cout << "Searching image for possible eyes..." << endl;
        t = (double)cvGetTickCount();
        for (int i=0; i < width*height*bpp; i+=bpp) 
        {
            // set pixel color vals (0 if black, -1 if not)
            red = img->imageData[i];
            green = img->imageData[i+1];
            blue = img->imageData[i+2];
            
            // if the pixel registers as not black...
            if (pixel_is_white (red, green, blue))
            {
                // stepped into if condition!
                stepped = true;
            
                // run pupil detection with this pixel as a seed
                Point seed = point_of_pixel (i, width, height);
                if (seed != Point(-1, -1))
                    result = ffill (input, seed);
                // problem processing the image
                else
                    return -2;
            }
        }
        t = (double)cvGetTickCount() - t;
        printf( "Detection time = %g ms\n",
                t/((double)cvGetTickFrequency()*1000.) );
    
        // release IplImage
        cvReleaseImage(&img);
        
        // write the result to the eye_result folder
        String resultPath = "eye_result/" + name;
        /* PLEASE NOTE: If the if condition is never stepped into, a result
         * image is never produced, therefore, save original image */
        if (stepped)
        {
            if ( !imwrite( resultPath, result ) )
            {
                cout << "Couldn't write " << resultPath << endl;
                return -3;
            }
        }
        
        // return input if unchanged
        else
        {
            if ( !imwrite( resultPath, input ) )
            {
                cout << "Couldn't write " << resultPath << endl;
                return -4;   
            }
        }
        
        return 0;
    }
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

/*
 * Function that runs floodFill on an image in order to locate certain objects,
 * then drawing circles on the objects on a copied image. The image with
 * the superimposed circles is returned.
 */

Mat ffill (Mat& input, Point seed)
{   
    // initialize floodfill vars
    Mat fimg;
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
    
    // return image with "eye" detected
    return input;
}
