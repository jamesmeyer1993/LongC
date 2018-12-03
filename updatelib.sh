#!/bin/bash
#
# updatelib.sh

updateList="updatelib.txt"
installDir="/usr/include/longc"
differ=""

# copy over files
while read -r line
do
  cp -v "$line" "$installDir/$line"
done < "$updateList"
