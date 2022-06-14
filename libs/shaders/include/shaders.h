#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "glad/glad.h"

GLuint LoadShader(const char *vertex_path, const char *fragment_path);