#pragma once

#include "glad/glad.h"

#include <GLFW/glfw3.h>
#include "miniaudio.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void setWindowHints(int major, int minor);
GLFWwindow* initializeWindow(const char* title, int major, int minor);
void initializeOpenGL(int posX, int posY, int width, int height);
void initializeAudio(ma_engine* engine);