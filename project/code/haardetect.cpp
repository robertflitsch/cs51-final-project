/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * haardetect.cpp
 *
 * Bobby Flitsch
 * Aaron Graham-Horowitz
 * TJ Barber
 * Hikari Senju
 *
 * CS51 Final Project
 *
 * This program runs eye detection on an image file using haar cascade
 * classifiers (which are passed in as command line arguments). The program
 * first loads the image from the path passed in at the command line,
 * processes it using cascade classifiers, draws filled circles over the
 * detected "eyes" and then saves it as an image file in the "haar_result"
 * directory.
 *
 * Please note: The main functionality of this program has been borrowed from
 * the example code "facedetect.cpp" provided by OpenCV. Our work on this
 * file was commenting it, so that we could understand its functionality,
 * removing the webcam and AVI functionality, (we just wanted to process 
 * images because my (Bobby's) webcam won't work in the appliance) and adding
 * in additional I/O capabilities so that it worked in a way that was helpful
 * in running our comparison program.
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
    cout << "\nThis program demonstrates the cascade recognizer. Now you can "
            "use Haar or LBP features.\n"
            "This classifier can recognize many ~rigid objects, it's most "
            "known use is for faces.\n"
            "Usage:\n"
            "./haardetect [--cascade=<cascade_path> this is the primary "
            "trained classifier such as frontal face]\n"
               "   [--nested-cascade[=nested_cascade_path this an optional "
               "secondary classifier such as eyes]]\n"
               "   [--scale=<image scale greater or equal to 1, try 1.3 for "
               "example>\n"
               "   [filename|camera_index]\n\n"
            "see facedetect.cmd for one call:\n"
            "./haardetect "
            "--cascade=\"cascades/haarcascade_frontalface_alt.xml\" "
            "--nested-cascade=\"cascades/haarcascade_eye.xml\" --scale=1.3 \n"
            "Hit any key to quit.\n"
            "Using OpenCV version " << CV_VERSION << "\n" << endl;
}

void detectAndDraw( Mat& img,
                   CascadeClassifier& cascade, 
                   CascadeClassifier& nestedCascade,
                   double scale, String inputName);

String cascadeName = "haarcascade_frontalface_alt.xml";
String nestedCascadeName = "haarcascade_eye.xml";

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
    cout << "Running haardetect..." << endl;

    // initialize the cascade and nested cascade classifiers
    CascadeClassifier cascade, nestedCascade;
    double scale = 1;

    // process the cascade and nested cascade classifiers
    for( int i = 1; i < argc; i++ )
    {
        // process cascade classifier (if given)
        cout << "Processing " << i << " " <<  argv[i] << endl;
        if( cascadeOpt.compare( 0, cascadeOptLen, argv[i], 
                                cascadeOptLen ) == 0 )
        {
            cascadeName.assign( argv[i] + cascadeOptLen );
            cout << "  from which we have cascadeName= " << cascadeName 
                 << endl;
        }
        
        // process nested cascade classifier (if given)
        else if( nestedCascadeOpt.compare( 0, nestedCascadeOptLen, argv[i],
                                           nestedCascadeOptLen ) == 0 )
        {
            if( argv[i][nestedCascadeOpt.length()] == '=' )
                nestedCascadeName.assign( argv[i] + 
                                          nestedCascadeOpt.length() + 1 );
            if( !nestedCascade.load( nestedCascadeName ) )
                cerr << "WARNING: Could not load classifier cascade for "
                        "nested objects" << endl;
        }
        
        // process scale (if given)
        else if( scaleOpt.compare( 0, scaleOptLen, argv[i], 
                                   scaleOptLen ) == 0 )
        {
            if( !sscanf( argv[i] + scaleOpt.length(), "%lf", 
                         &scale ) || scale < 1 )
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

    // if inputName not assigned, try to get feed from cam
    if( inputName.empty() || 
        (isdigit(inputName.c_str()[0]) && inputName.c_str()[1] == '\0') )
    {
        capture = cvCaptureFromCAM( inputName.empty() ? 
                                    0 : inputName.c_str()[0] - '0' );
        int c = inputName.empty() ? 0 : inputName.c_str()[0] - '0' ;
        if(!capture) cout << "Capture from CAM " <<  c << " didn't work" 
                          << endl;
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

            detectAndDraw( frameCopy, cascade, nestedCascade, scale, 
                           inputName );

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
                        detectAndDraw( image, cascade, nestedCascade, scale, 
                                       inputName );
                        c = waitKey(0);
                        if( c == 27 || c == 'q' || c == 'Q' )
                            break;
                    }
                    else
                    {
                    	cerr << "Aw snap, couldn't read image " << buf 
                    	     << endl;
                    }
                }
                fclose(f);
            }
        }
    }

    return 0;
}

// the actual detection code
void detectAndDraw( Mat& img,
                   CascadeClassifier& cascade, 
                   CascadeClassifier& nestedCascade,
                   double scale, String inputName)
{
    /* BEGINNING OF CODE WE NEED TO REPLACE */
    // initialize vars
    int i = 0;
    double t = 0;
    vector<Rect> faces;
    const static Scalar colors[] =  { CV_RGB(0,0,255),
        CV_RGB(0,128,255),
        CV_RGB(0,255,255),
        CV_RGB(0,255,0),
        CV_RGB(255,128,0),
        CV_RGB(255,255,0),
        CV_RGB(255,0,0),
        CV_RGB(255,0,255)} ;
    Mat gray, smallImg( cvRound (img.rows/scale), cvRound(img.cols/scale), 
                        CV_8UC1 );
    int pos;
    String name, path;

    /* take "img" and convert it to gray-scale: "gray." the rest of the code 
     *is processing the new "gray" img */
    cvtColor( img, gray, CV_BGR2GRAY );
    resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    // find objects in image that match the haar classifiers -store in "faces"
    t = (double)cvGetTickCount();
    cascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        //|CV_HAAR_FIND_BIGGEST_OBJECT
        //|CV_HAAR_DO_ROUGH_SEARCH
        |CV_HAAR_SCALE_IMAGE
        ,
        Size(30, 30) );
    t = (double)cvGetTickCount() - t;
    printf( "detection time = %g ms\n", 
            t/((double)cvGetTickFrequency()*1000.) );
    
    // detection done, faces stored as rects, now print the stuff to the image
    for( vector<Rect>::const_iterator r = faces.begin(); 
         r != faces.end(); r++, i++ )
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
        /* PLEASE NOTE: The following call to cv::circle in commented out so 
         * that only eyes are circled */
        //circle( img, center, radius, color, -1, 8, 0 );
        if( nestedCascade.empty() )
            continue;
        smallImgROI = smallImg(*r);
        nestedCascade.detectMultiScale( smallImgROI, nestedObjects,
            1.1, 2, 0
            //|CV_HAAR_FIND_BIGGEST_OBJECT
            //|CV_HAAR_DO_ROUGH_SEARCH
            //|CV_HAAR_DO_CANNY_PRUNING
            |CV_HAAR_SCALE_IMAGE
            ,
            Size(30, 30) );
            
        // draw nested cascade circles
        for( vector<Rect>::const_iterator nr = nestedObjects.begin(); 
             nr != nestedObjects.end(); nr++ )
        {
            center.x = cvRound((r->x + nr->x + nr->width*0.5)*scale);
            center.y = cvRound((r->y + nr->y + nr->height*0.5)*scale);
            radius = cvRound((nr->width + nr->height)*0.25*scale);
            /* NOTE: circumfrance width is set to negative so that circles
            * are filled in for use in the comparison function */
            circle( img, center, radius, color, -1, 8, 0 );
        }
    }
    
    // get just image name
    pos = inputName.find ("/");
    name = inputName.substr (pos);
    
    // create path
    path = "haar_result" + name;
    
    // save the image to the folder
    if ( !imwrite( path, img ) )
        cout << "Couldn't write " << path << endl;
}
