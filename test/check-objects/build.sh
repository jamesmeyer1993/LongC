#!/bin/sh
# run "$sh build [output file]"

#check user input
output=$1
if [ "$#" -eq "0" ] ; then
	echo "No input provided. Compiling default executable test."
	output="test"
fi
mkdir "bin"

# compiling
gcc src/test.c \
	src/obj/types.h \
	src/obj/object.h \
	src/obj/object.c \
	-o bin/test

echo "Successful build. The executable is bin/$1"
