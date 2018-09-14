#!/bin/bash

# check user input
if [ "$#" -eq "0" ] ;
  then
  echo "No test directory provided. Exiting..."
  exit
fi

# update options
if [ "$1" = "bytearray-test" ] ;
  then
  origin="../src"
  destination="bytearray-test"
  cp -v "$origin/byte.c" "$destination/byte.c"
  cp -v "$origin/byte.h" "$destination/byte.h"
fi
