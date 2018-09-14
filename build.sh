#!/bin/sh

gcc src/implementation.c \
	src/obj/types.h \
	src/obj/object.h \
	src/obj/object.c \
	-o bin/test
