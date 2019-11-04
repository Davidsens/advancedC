#!/bin/bash

read -p "Bitte geben Sie einen Dateinamen ein: " DNAME   # liest nach ./TimNeidig_problem3.sh die Variable VNAME

avconv -i  $DNAME -vsync 1 -r 50 out-%03d.jpg            # s.3.a) convert a video of your choice to a sequence of images

convert -delay 20 -loop 1 out-*.jpg animated.gif         # s.3.b) convert this sequence of images to an animated gif

rm *.jpg
