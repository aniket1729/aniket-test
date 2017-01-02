#!/bin/sh
if [ ! -d ./binaries ]; then
   mkdir ./binaries
fi
g++ max_min_algo.cpp -o ./binaries/max_min_algo
g++ second_largest.cpp -std=c++0x -o ./binaries/second_largest
g++ segmented_sieve.cpp -o ./binaries/segmented_sieve
