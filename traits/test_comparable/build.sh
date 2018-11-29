#!/bin/sh

main="$1"

if [ "$(grep -c "#include \"../trait.h\"" "$main")" -eq "1" ] ;
then
  trait=$(grep "TRAIT" "$main")

  trait_t=$(echo "$trait" | rev | sed 's/,.*//; s/ //g; s/;)//' | rev)

  trait=$(grep "TRAIT" "$main" | sed 's/TRAIT//; s/(//; s/)//; s/ //g; s/,.*//')

  trait_h="$trait.h"
  trait_h=$(grep -i -n "$trait_h" "$main")
  trait_h=$(echo "$trait_h" | sed 's/..//; s/ //g; s/#include//; s/\"//g;')

  start=$(grep -n -i "${trait}_TRAIT" "${trait_h}" | sed 's/:.*//; s/://')
  end=$(wc -l "${trait_h}" | sed 's/ .*//; s/ //')
  #echo $start
  #echo $end
  tail --lines=$(($end - $start + 1)) "${trait_h}"
fi

#gcc -g -Wall -pedantic -std=c11 "$main"
