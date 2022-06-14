#pragma once

#include "renderer.h"
#include <GLFW/glfw3.h>


extern glm::mat4 proj;
extern glm::mat4 view;

void update(GLFWwindow* window, float physicsTime);