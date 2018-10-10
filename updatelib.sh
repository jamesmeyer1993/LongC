#!/bin/bash
#
# updatelib.sh

updateList="updatelib.txt"
installDir="/usr/include/longc"
differ=""

# copy over files
while read -r line
do
  differ="$(echo $(ls -1 $installDir/*) | grep -c $line )"
  if [ "$differ" == "0" ] ; then
    cp -v "$line" "$installDir/$line"
  fi
done < "$updateList"

# copy files that have been changed
while read -r line
do
  differ="$(echo $(diff -q $line $installDir/$line) | grep -c "differ")"
  if [ "$differ" == "1" ] ; then
    cp -v "$line" "$installDir/$line"
  fi
done < "$updateList"
