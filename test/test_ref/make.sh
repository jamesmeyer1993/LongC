#!/bin/bash
#
# make.sh
# - compiles test.c
# - format:
#   dependency1.o \
#   dependency2.o \
#   ...
#   main.c -o [output]

longc="/usr/include/longc"

gcc "$longc/lang/reference.o" \
  test.c \
  -o $1
