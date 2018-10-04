#!/bin/bash
#
# build.sh
# - generates the object files for longc
#	- generally used in conjunction with ubdate lib

all(){
	primitves
}

primitives(){
	echo "building primitives..."
	gcc -c lang/primitives.h -o lang/primitives.o
}

# begin main
