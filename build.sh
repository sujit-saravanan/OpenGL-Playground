#!/bin/zsh
cmake -S . -B build
cd build || exit
make
./OpenGLRetro