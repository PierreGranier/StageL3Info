#! /bin/bash

make clean
make all

if [ $1 ]
then
    cat $1
    ./verificateur $1
else
    ./verificateur
fi
