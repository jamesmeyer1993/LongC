#!/bin/sh

main="$1"

if [ "$(grep -c "#include \"../trait.h\"" "$main")" -eq "1" ] ;
then
  # find the TRAIT macro
  trait=$(grep "TRAIT" "$main")

  # find the type the TRAIT applies to
  trait_t=$(echo "$trait" | rev | sed 's/,.*//; s/ //g; s/;)//' | rev)

  # find the name of the TRAIT
  trait=$(grep "TRAIT" "$main" | sed 's/TRAIT//; s/(//; s/)//; s/ //g; s/,.*//')

  # find create the path for the header file
  trait_h="$trait.h"
  trait_h=$(grep -i -n "$trait_h" "$main")
  trait_h=$(echo "$trait_h" | sed 's/..//; s/ //g; s/#include//; s/\"//g;')

  start=$(grep -n -i "${trait}_TRAIT" "${trait_h}" | sed 's/:.*//; s/://')
  end=$(tail --lines=$(($start)) "${trait_h}" | grep -c '\\')
  end=$(( $start + $end ))

  echo "$start"
  echo "$end"
fi

#gcc -g -Wall -pedantic -std=c11 "$main"
