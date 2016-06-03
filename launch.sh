#! /bin/bash

cd AnalyseurSyntaxique
make all

cd ../InterfaceGraphique
cmake CMakeLists.txt
make --file=Makefile -j2

./NomApp