#!/bin/sh

if [ "$1" = "compare" ] ; then
        if [ -x facecompare ] ; then
                echo "Comparison function not yet implemented"
        else
                echo 'ERROR: Project file "facecompare" not found'
        fi
else
        if [ -x haardetect ] ; then
            ./haardetect --cascade="cascades/haarcascade_frontalface_alt.xml" --nested-cascade="cascades/haarcascade_eye.xml" --scale=1.3 lena.bmp 
        else
            echo 'ERROR: Project file "haardetect" not found'
            
        fi
        
        if [ -x skintonedetect ] ; then
            ./skintonedetect --cascade="cascades/haarcascade_frontalface_alt.xml" --nested-cascade="cascades/haarcascade_eye.xml" --scale=1.3 lena.bmp
        else
            echo 'ERROR: Project file "skintonedetect" not found'
            
        fi
fi
