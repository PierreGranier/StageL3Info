#! /bin/bash

cd AnalyseurSyntaxical
make all

cd ../IntergrapheFagique
cmake CMakeLists.txt
make --file=Makefile -j2

./IntergrapheFagique/NomApp