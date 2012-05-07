/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * eyedetect_beta.cpp
 *
 * Bobby Flitsch
 * Aaron Graham-Horowitz
 * TJ Barber
 * Hikari Senju
 *
 * CS51 Final Project
 *
 * This is the code that was sent in for the Beta Checkpoint. It uses the
 * code borrowed from the "facedetect.cpp" demo file provided by OpenCV to try
 * and find an "edge" on the input image, and then use flood_fill from that
 * image based off of the nearby pixel colors.
 *
 * At this point, we had read through, and understood much of the
 * functionality behind the eye detection using haar cascades, and other
 * methods of image processing, including "canny edge detection", however, we
 * did not realize that our method for iterating through the image pixels was
 * faulty (because of our pointers to the cv::Mat data). As such, this program
 * "detects" the eye, however, it has many problems printing the data onto the
 * image. As well, since the pointers are passed around incorrectly, the
 * program segfaults on many images. It should not be ran because of these
 * bugs, as it has very unpredictable behavior, but I have included it with
 * the Developmental Code, because it was for our Beta checkpoint, and so that
 * the progression between this and the final "eyedetect.cpp" file may be
 * seen. Much work and refinement went into this file to produce the final
 * product.
 *
 * Please note: as may be noticed right away, this file has not been edited to
 * be within 80 chars per line. It has not been edited as such because when
 * we handed this into Tony, it was EXACTLY as follows. I did not want to edit
 * the file, incase it would be used in reference to the file that was handed
 * in to Tony. This would make it harder for you to read and check between the
 * files. I hope that this is more conveinient for you in grading.
 *
 * Also please note: The program should be called with the following:
 * ./eyedetect_beta --cascade="../cascades/haarcascade_frontalface_alt.xml" 
 * --nested-cascade="../cascades/haarcascade_eye.xml" --scale=1.3 <image path>
 *
 * This program will work on eye.bmp.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void help()
{
    cout << "\nThis program demonstrates the cascade recognizer. Now you can use Haar or LBP features.\n"
            "This classifier can recognize many ~rigid objects, it's most known use is for faces.\n"
            "Usage:\n"
            "./haardetect [--cascade=<cascade_path> this is the primary trained classifier such as frontal face]\n"
               "   [--nested-cascade[=nested_cascade_path this an optional secondary classifier such as eyes]]\n"
               "   [--scale=<image scale greater or equal to 1, try 1.3 for example>\n"
               "   [filename|camera_index]\n\n"
            "see haardetect.cmd for one call:\n"
            "./haardetect --cascade=\"haarcascade_frontalface_alt.xml\" --nested-cascade=\"haarcascade_eye.xml\" --scale=1.3 \n"
            "Hit any key to quit.\n"
            "Using OpenCV version " << CV_VERSION << "\n" << endl;
}

void detectAndDraw( Mat& img,
                   CascadeClassifier& cascade, CascadeClassifier& nestedCascade,
                   double scale, String inputName );

String cascadeName = "haarcascade_frontalface_alt.xml";
String nestedCascadeName = "haarcascade_eye_tree_eyeglasses.xml";

int main( int argc, const char** argv )
{
    // *camera for attempted campture?*
    CvCapture* capture = 0;
    
    // data structures initialized that store frame, frame copy, and image
    Mat frame, frameCopy, image;
    const String scaleOpt = "--scale=";
    size_t scaleOptLen = scaleOpt.length();
    const String cascadeOpt = "--cascade=";
    size_t cascadeOptLen = cascadeOpt.length();
    const String nestedCascadeOpt = "--nested-cascade";
    size_t nestedCascadeOptLen = nestedCascadeOpt.length();
    
    // input (will be set to 5th command line argument)
    String inputName;

    help();

    // initialize the cascade and nested cascade classifiers
    CascadeClassifier cascade, nestedCascade;
    double scale = 1;

    // process the cascade and nested cascade classifiers
    for( int i = 1; i < argc; i++ )
    {
        // process cascade classifier (if given)
        cout << "Processing " << i << " " <<  argv[i] << endl;
        if( cascadeOpt.compare( 0, cascadeOptLen, argv[i], cascadeOptLen ) == 0 )
        {
            cascadeName.assign( argv[i] + cascadeOptLen );
            cout << "  from which we have cascadeName= " << cascadeName << endl;
        }
        
        // process nested cascade classifier (if given)
        else if( nestedCascadeOpt.compare( 0, nestedCascadeOptLen, argv[i], nestedCascadeOptLen ) == 0 )
        {
            if( argv[i][nestedCascadeOpt.length()] == '=' )
                nestedCascadeName.assign( argv[i] + nestedCascadeOpt.length() + 1 );
            if( !nestedCascade.load( nestedCascadeName ) )
                cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;
        }
        
        // process scale (if given)
        else if( scaleOpt.compare( 0, scaleOptLen, argv[i], scaleOptLen ) == 0 )
        {
            if( !sscanf( argv[i] + scaleOpt.length(), "%lf", &scale ) || scale < 1 )
                scale = 1;
            cout << " from which we read scale = " << scale << endl;
        }
        
        // assign 5th argument to inputName (if given)
        else if( argv[i][0] == '-' )
        {
            cerr << "WARNING: Unknown option %s" << argv[i] << endl;
        }
        else
            inputName.assign( argv[i] );
    }

    // if one of the cascades cannot load
    if( !cascade.load( cascadeName ) )
    {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        cerr << "Usage: facedetect [--cascade=<cascade_path>]\n"
            "   [--nested-cascade[=nested_cascade_path]]\n"
            "   [--scale[=<image scale>\n"
            "   [filename|camera_index]\n" << endl ;
        return -1;
    }

    // if no extra command args (inputName not assigned) try to get feed from cam
    if( inputName.empty() || (isdigit(inputName.c_str()[0]) && inputName.c_str()[1] == '\0') )
    {
        capture = cvCaptureFromCAM( inputName.empty() ? 0 : inputName.c_str()[0] - '0' );
        int c = inputName.empty() ? 0 : inputName.c_str()[0] - '0' ;
        if(!capture) cout << "Capture from CAM " <<  c << " didn't work" << endl;
    }
    
    // try to get feed from video file path passed in as arg
    else if( inputName.size() )
    {
        image = imread( inputName, 1 );
        if( image.empty() )
        {
            capture = cvCaptureFromAVI( inputName.c_str() );
            if(!capture) cout << "Capture from AVI didn't work" << endl;
        }
    }
    
    // try to get the image path passed in as arg
    else
    {
        image = imread( "lena.jpg", 1 );
        if(image.empty()) cout << "Couldn't read lena.jpg" << endl;
    }
    
    /*
    int cvNamedWindow(const char* name, int flags)
    
    args:
        * name – Name of the window in the window caption that may be used as 
                 a window identifier.
        * flags – Flags of the window. Currently the only supported flag is 
                  CV_WINDOW_AUTOSIZE . If this is set, window size is 
                  automatically adjusted to fit the displayed image (see 
                  ShowImage ), and the user can not change the window size 
                  manually.
    */

    // open window to display image(s)
    cvNamedWindow( "result", 1 );

    // get capture from cam or avi
    if( capture )
    {
        cout << "In capture ..." << endl;
        for(;;)
        {
            IplImage* iplImg = cvQueryFrame( capture );
            frame = iplImg;
            if( frame.empty() )
                break;
            if( iplImg->origin == IPL_ORIGIN_TL )
                frame.copyTo( frameCopy );
            else
                flip( frame, frameCopy, 0 );

            detectAndDraw( frameCopy, cascade, nestedCascade, scale, inputName );

            if( waitKey( 10 ) >= 0 )
                goto _cleanup_;
        }

        // wait for a key to be pressed
        waitKey(0);

_cleanup_:
        // release the curren capture feed
        cvReleaseCapture( &capture );
    }
    
    // get image to work on
    else
    {
        cout << "In image read" << endl;
        if( !image.empty() )
        {
            // run the detection code with the command line args
            detectAndDraw( image, cascade, nestedCascade, scale, inputName );
            
            // wait for a key to be pressed
            waitKey(0);
        }
        else if( !inputName.empty() )
        {
            /* assume it is a text file containing the
            list of the image filenames to be processed - one per line */
            FILE* f = fopen( inputName.c_str(), "rt" );
            if( f )
            {
                char buf[1000+1];
                while( fgets( buf, 1000, f ) )
                {
                    int len = (int)strlen(buf), c;
                    while( len > 0 && isspace(buf[len-1]) )
                        len--;
                    buf[len] = '\0';
                    cout << "file " << buf << endl;
                    image = imread( buf, 1 );
                    if( !image.empty() )
                    {
                        // run the detection code on the certain image
                        detectAndDraw( image, cascade, nestedCascade, scale, inputName );
                        c = waitKey(0);
                        if( c == 27 || c == 'q' || c == 'Q' )
                            break;
                    }
                    else
                    {
                    	cerr << "Aw snap, couldn't read image " << buf << endl;
                    }
                }
                fclose(f);
            }
        }
    }

    // destroy the result window and end program
    cvDestroyWindow("result");

    return 0;
}

// the actual detection code
void detectAndDraw( Mat& img,
                   CascadeClassifier& cascade, CascadeClassifier& nestedCascade,
                   double scale, String inputName )
{
    // initialize vars
    int i = 0;
    double t = 0;
    vector<Rect> eyes;
    const static Scalar colors[] =  { CV_RGB(0,0,255),
        CV_RGB(0,128,255),
        CV_RGB(0,255,255),
        CV_RGB(0,255,0),
        CV_RGB(255,128,0),
        CV_RGB(255,255,0),
        CV_RGB(255,0,0),
        CV_RGB(255,0,255)} ;
    Mat gray, smallImg( cvRound (img.rows/scale), cvRound(img.cols/scale), CV_8UC1 ), edges, centers;
    
    // Kernel size
	int N = 7;
    
    // Edge Detection Variables
	int aperature_size = N;
	double lowThresh = 800;
	double highThresh = 1000;
    

    // take "img" and convert it to gray-scale: "gray." the rest of the code is processing the new "gray" img
    cvtColor( img, gray, CV_BGR2GRAY );
    resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );
    
    /* canny edge detect */
    
    Canny (smallImg, edges, lowThresh*N*N, highThresh*N*N, N);
    
    // iterate through pixels and find seed
    
   uchar *edge = (uchar*)(edges.data);
   uchar *gptr = (uchar*)(gray.data);
   int ct = 0;
   Point seed;
   Scalar color = CV_RGB(0,0,255);
   Rect *eye;
   
    
      
    for(int i=0; i<edges.rows; i++)
    {
        for(int j=0; j<edges.cols; j++)
        {
            // if pixel is an edge (white)
            if (edge[ct] < 5 && edge[ct+1] < 5 && edge[ct+2] < 5)
            {    
                // update seed
                seed = Point(i, j);
                
                // fill in nearby pixels
                if (gptr[ct-9] < 2 && gptr[ct-8] < 2 && gptr[ct-7] < 2)
                floodFill ( img, seed, color, eye, Scalar::all(2.0), Scalar::all(2.0), FLOODFILL_FIXED_RANGE);
            }
            
            ct += 3;
        }
    }
    
    
    // detection done, faces stored as rects, now print the stuff to the image
   /* for( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )
    {
        Mat smallImgROI;
        vector<Rect> nestedObjects;
        Point center;
        Scalar color = colors[i%8];
        int radius;
        
        // set the vars to values based off of the faces rects
        center.x = cvRound((r->x + r->width*0.5)*scale);
        center.y = cvRound((r->y + r->height*0.5)*scale);
        radius = cvRound((r->width + r->height)*0.25*scale);
        
        // draw the cascade circles
        /* EDITED TO MAKE FULL CIRCLES, RATHER THAN EDGES, FOR COMPARISON */
       /* circle( img, center, radius, color, 3, 8, 0 );
    }*/
    
    // save the image to the folder
    /*if ( !imwrite( ("eye_result/" + inputName), img ) )
        cout << "Couldn't write file" << endl;*/
          
    // put the image in a window
    cv::imshow( "result", img );
}
