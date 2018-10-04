#!/bin/bash
#
# updatelib.sh

updateList="updatelib.txt"
installDir="/usr/include/longc"
differ=""

while read -r line
do
  differ="$(echo $(diff -q $line $installDir/$line) | grep -c "differ")"
  if [ "$differ" == "1" ] ; then
    cp -v "$line" "$installDir/$line"
  fi
done < "$updateList"
