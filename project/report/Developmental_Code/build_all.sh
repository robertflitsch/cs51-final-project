#!/bin/sh

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# ./build_all.sh
#
# Bobby Flitsch
# Aaron Graham-Horowitz
# TJ Barber
# Hikari Senju
#
# CS51 Final Project
#
# The following bash script was provided by Tony. Since all of our files use
# only c++ as a language, and not c, I have edited the script that Tony gave us
# to only compile c++ files.
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

for i in *.cpp; do
    echo "compiling $i"
    g++ -ggdb `pkg-config --cflags opencv` -o `basename $i .cpp` $i `pkg-config --libs opencv`;
done

