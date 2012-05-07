/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * compare.cpp
 *
 * Bobby Flitsch
 * Aaron Graham-Horowitz
 * TJ Barber
 * Hikari Senju
 *
 * CS51 Final Project
 *
 * This program takes two image paths as command line arguments (one of which
 * is supposed to have had haardetect ran on it and one that is supposed to
 * have had eyedetect ran on it), loads the images from those paths, (as
 * IplImages because of their pixel iterating capabilities (*please see 
 * "Also please note:" in "eyedetect.cpp" for an explanation of this design
 * decision*) then iterates over both images (provided they are the same size)
 * and compares their respective pixels for equality along all three channels.
 * The final resulting difference (in percent of pixels different) is printed
 * in the terminal at the end, and the "eye_result" and "haar_result" images
 * are displayed.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

// prototype declarations
void img_compare ( IplImage *image1, IplImage *image2 );
bool pixel_comp ( int red1, int green1, int blue1,
                  int red2, int green2, int blue2 );

int main( int argc, const char** argv )
{
    // if not correct # argc, then function called incorrectly
    if (argc != 3)
    {
        cout << "Incorrect command line call. Please format "
                "your call to match the following:\n"
                "./compare <image1_path> <image2_path>" << endl;
        return -1;
    }
    
    // process images
    else
    {
        // print that comparison is starting
        cout << "Running comparison..." << endl;

        // initialize vars
        String pic1, pic2;
        const char *path1;
        const char *path2;
        IplImage *image1;
        IplImage *image2;
    
        // get image names
        pic1.assign( argv[1] );
        pic2.assign( argv[2] );
        
        // convert strings to const char*s
        path1 = pic1.c_str();
        path2 = pic2.c_str();
        
        // read images to IplImages
        cout << "Loading " << path1 << endl;
        image1 = cvLoadImage(path1, CV_LOAD_IMAGE_UNCHANGED);
        cout << "Loading " << path2 << endl;
        image2 = cvLoadImage(path2, CV_LOAD_IMAGE_UNCHANGED);
        
        // check that images were loaded
        if ( !image1 )
        {
            cout << "Oops, couldn't read " << path1 << endl;
            return -2;
        }
        
        else if ( !image2 )
        {
            cout << "Oops, couldn't read " << path2 << endl;
            return -3;
        }
            
        // run comparison function on the images
        else
        {
            // open windows for showing result images
            cvNamedWindow( "haar_result", 1 );
            cvNamedWindow( "eye_result", 1 );
        
            // run compare code
            img_compare( image1, image2 );
            
            // wait for a key to be pressed then destroy windows
            waitKey(0);
            cvDestroyWindow("haar_result");
            cvDestroyWindow("eye_result");
            
            // release Ipls
            cvReleaseImage(&image1);
            cvReleaseImage(&image2);
            
            return 0;
        }
    }
}

/*
 * Functional part of this file. Takes in pointers to 2 IplImages and runs the
 * image comp
 */

void img_compare ( IplImage *image1, IplImage *image2 )
{
    // initialize vars
    int width1 = image1->width; 
    int height1 = image1->height;
    int width2 = image2->width; 
    int height2 = image2->height;
    int bpp = image1->nChannels;
    int pixels = height1 * width1;
    int unequal = 0;
    int red1, green1, blue1;
    int red2, green2, blue2;
    float diff;
    double t;
    
    // check that images are same size
    if ( width1 != width2 || height1 != height2 )
        cout << "Images are not comparable (different sizes)" << endl;
        
    else
    {
        // run comparison
        cout << "Comparing images..." << endl;
        
        // iterate through pixels of each image
        for (int i=0; i < width1*height1*bpp; i+=bpp) 
        {
            // set pixel color vals (0 if black, -1 if not)
            red1 = image1->imageData[i];
            green1 = image1->imageData[i+1];
            blue1 = image1->imageData[i+2];
            
            red2 = image2->imageData[i];
            green2 = image2->imageData[i+1];
            blue2 = image2->imageData[i+2];
        
            // if the pixel registers as not black...
            if (!pixel_comp (red1, green1, blue1, red2, green2, blue2))
            {
                // pixel isn't equal!
                unequal++;
            }
        }
        
        // determine percentage difference
        diff = ((float)unequal / (float)pixels) * 100.0;
        cout << "The difference between these pictures is " 
             << diff << "%" << endl;
        
        // display images for comparison
        cvShowImage( "haar_result", image1 );
        cvShowImage( "eye_result", image2 );
    }      
}

/*
 * Function that takes in the values for 2 pixels and checks to see
 * whether they are equal or not (assumed to work off of 3 separate channels
 * of 2 IplImage pixels)
 */

bool pixel_comp ( int red1, int green1, int blue1,
                  int red2, int green2, int blue2 )
{
    bool result;
    result = red1 == red2 && green1 == green2 && blue1 == blue2;
    return result;
}
