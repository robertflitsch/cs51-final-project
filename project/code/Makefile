CC=g++
CFLAGS= -g -Wall -O2
LIB_FLAGS = -lm -lopencv_core -lopencv_highgui -lopencv_video -lopencv_imgproc -lopencv_gpu -lopencv_calib3d -lopencv_legacy -lopencv_objdetect -lopencv_ml -lopencv_features2d -lopencv_calib3d -lopencv_flann

LDFLAGS = -I/usr/include/opencv $(LIB_FLAGS)

# Source files in the pipeline
# SRC = ImageProcessor.cpp Pipeline.cpp GPreProcessor.cpp MorphologyProcessor.cpp ThresholdProcessor.cpp ContourProcessor.cpp PyramidSegProcessor.cpp CannyEdgeProcessor.cpp ScoringProcessor.cpp CoalescingProcessor.cpp
OBJECT = $(SRC:.cpp=.o)

UNAME := $(shell uname)

all: processor

# Tests for the processor module
test_processor: test/TestProcessor.o
	$(CC) $(CFLAGS) $(LDFLAGS) test/TestProcessor.o -o test_processor

# This is the executable processing pipeline
processor: $(OBJECT)
	$(CC) $(CFLAGS) -o pipeline $(OBJECT) $(LDFLAGS)

# Compiles cpp to object files
.cpp.o:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

# Cleans targets
clean:
	rm -rf *.o core* test_processor pipeline

run: processor
	./pipeline