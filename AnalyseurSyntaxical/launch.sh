#! /bin/bash

make clean
make all
cat $1
./verificateur $1