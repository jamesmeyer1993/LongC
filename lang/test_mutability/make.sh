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

status="cmplstatus.txt"
echo "$(gcc "$longc/lang/reference.h" "$longc/lang/reference.o" "$1" -o "$2")" \
  | grep -c "error" > "$status"

if [ "$(echo $(cat "$status") | grep -c "error")" -eq "0" ] ; then
  printf "Successful compilation: $1  -->   $2\n\n"
fi

rm "$status"
