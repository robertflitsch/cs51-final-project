#!/bin/sh

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# ./run_beta.sh
#
# Bobby Flitsch
# Aaron Graham-Horowitz
# TJ Barber
# Hikari Senju
#
# CS51 Final Project
#
# The following bash script is used to automatically run the eyedetect_beta
# program. This bash script has been created because the command line arguments
# necessary to pass in the cascade classifiers and image paths are really
# tedius. The script will default to running the program on "eye.bmp", however,
# if you would like to run the program on an alternate image, the default path
# can be overridden by passing in an argument to the bash script, which
# will run it on the path that is passed to it. For example, the possible calls
# to this script may be one of the following:
# ./run_beta.sh
# OR
# ./run_beta.sh <alternate_image_path>
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# If we are running on Aaron's computer, fix the library path so we can
# access OpenCV.
if  [ "`id -u -n`" = "aaron" ] ; then
        export LD_LIBRARY_PATH=/home/aaron/P/OpenCV-2.3.1/release/lib
fi

# Make directories to store our results if they do not already exist.
if [ ! -d black ] ; then
        mkdir black
fi

# Make sure necessary directories are present
if [ ! -d cascades ] ; then
        echo '"cascades/" directory not present.'
fi

if [ ! -d images ] ; then
        echo '"images/" directory not present.'
fi

# Run project in stages.
if [ $# = 0 ] ; then

        if [ -x eyedetect_beta ] ; then
                ./eyedetect_beta \
                --cascade="cascades/haarcascade_frontalface_alt.xml" \
                --nested-cascade="cascades/haarcascade_eye.xml" \
                --scale=1.0 images/eye.bmp
        else
                echo 'ERROR: Project file "eyedetect_beta" not found'
                exit 1
        fi
                
elif [ $# = 1 ] ; then

        if [ -x eyedetect_beta ] ; then
                ./eyedetect_beta \
                --cascade="cascades/haarcascade_frontalface_alt.xml" \
                --nested-cascade="cascades/haarcascade_eye.xml" \
                --scale=1.0 "$1"
        else
                echo 'ERROR: Project file "eyedetect_beta" not found'
                exit 1
        fi

else
        echo 'Incorrect call to script. Try: 
              ./run_beta.sh
              OR
              ./run_beta.sh <alternate_image_path>'
        
fi
