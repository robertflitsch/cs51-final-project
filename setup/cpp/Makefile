CC=gcc
CFLAGS= -Wall
LDFLAGS = -I/usr/local/include/opencv -lm -lopencv_core -lopencv_highgui -lopencv_video -lopencv_imgproc
SRC = kmeans.cpp
OBJECT = kmeans.o
ALL = kmeans

all: $(ALL)

test: $(OBJECT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJECT): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $<

.PHONY: clean

clean:
	rm -rf *.o core* $(ALL)



