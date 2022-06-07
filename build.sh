#!/bin/zsh
cmake -S src -B build
cd build || exit
make
./OpenGLRetro