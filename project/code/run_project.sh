#!/bin/sh

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# ./run_project.sh
#
# Bobby Flitsch
# Aaron Graham-Horowitz
# TJ Barber
# Hikari Senju
#
# CS51 Final Project
#
# The following bash script is used to automatically run the necessary 
# functions for eye detection and comparison of methods for use in the final
# project. This streamlines the command line call, which should be formatted
# as the following:
# ./run_project.sh <image_name>
#
# Please note: the image that will be processed is assumed to be located in
# the "images/" directory and is assumed to have a ".bmp" file extension. As
# such, the command line call should NOT have the file path OR file extension.
# This is for ease of typing. For example, a proper call to this script would
# be:
# ./run_project eye
# NOT:
# ./run_project images/eye.bmp
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
if [ ! -d haar_result ] ; then
        mkdir haar_result
fi
if [ ! -d eye_result ] ; then
        mkdir eye_result
fi

# Make sure necessary directories are present
if [ ! -d cascades ] ; then
        echo '"cascades/" directory not present.'
fi

if [ ! -d images ] ; then
        echo '"images/" directory not present.'
fi

# Run project in stages.
if [ $# != 1 ] ; then
        echo 'Project needs more input. Try "./run_project image.ext"'
        exit 1
else
        if [ -x haardetect ] ; then
                ./haardetect \
                --cascade="cascades/haarcascade_frontalface_alt.xml" \
                --nested-cascade="cascades/haarcascade_eye.xml" \
                --scale=1.0 images/"$1".bmp
        else
                echo 'ERROR: Project file "haardetect" not found'
                exit 1
        fi

        if [ -x eyedetect ] ; then
                ./eyedetect "$1".bmp
        else
                echo 'ERROR: Project file "eyedetect" not found'
                exit 1
        fi

        if [ -x compare ] ; then
                ./compare haar_result/"$1".bmp eye_result/"$1".bmp
        else
                echo 'ERROR: Project file "compare" not found'
                exit 1
        fi
fi
