#!/bin/bash

BUILD_TYPE="Debug"

if [ "$#" -eq 1 ]; then
  if [ "$1" == "Debug" ] || [ "$1" == "Release" ]; then
    BUILD_TYPE=$1
  else
    echo "Error: only 'Debug' or 'Release' are allowed."
    exit 1
  fi
elif [ "$#" -gt 1 ]; then
  echo "Error: the script accepts only one argument."
  exit 1
fi


mkdir cmake_build
cd cmake_build

# build
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ../
cmake --build ./

cd ../
