#!/bin/sh
g++ -Wall p009.cpp
./a.out > d0 & 
./a.out > d1 & 
./a.out > d2 & 
./a.out > d3 &
./a.out > d4 &

wait

cat d0 d1 d2 d3 d4
rm d0 d1 d2 d3 d4
