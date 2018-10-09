#!/bin/bash
#
# build.sh
# - generates the object files for longc
#	- generally used in conjunction with ubdate lib

build_all(){

}

# build longc/lang
build_lang(){
	build_primitives
	build_reference
}

build_primitives(){
	echo "building primitives.h"
	gcc -c lang/primitives.h -o lang/primitives.o
}

build_reference(){
	echo "building reference.h, reference.c"
	gcc -c lang/reference.h lang/reference.c -o lang/reference.o
}

# begin main
