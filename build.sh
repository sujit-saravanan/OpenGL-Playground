#!/bin/zsh
cmake -S . -B build
ninja -C build -j 20
./build/OpenGLRetro