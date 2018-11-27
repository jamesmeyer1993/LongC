#!/bin/sh
#
#

gcc -c -g -Wall -pedantic -std=c11 "../string.c" -o "../string.o"
gcc -g -Wall -pedantic -std=c11 "../string.o" "test.c" -o "test"
