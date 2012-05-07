REM an example of using haar cascade recognition for face and eye detection.
haardetect --cascade="cascades/haarcascade_frontalface_alt.xml" --nested-cascade="cascades/haarcascade_eye.xml" --scale=1.3 %1
