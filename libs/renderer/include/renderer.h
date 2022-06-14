#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "stb_image.h"
#include "shaders.h"


struct texture{
    GLuint id;
    int width;
    int height;
    int channels;
    unsigned char* bytes;
};

void generateTexture(texture *tex, const char *texture_path, GLint scaling_type, GLint wrapping_type);
void generateVAO(GLuint *id);
void generateBuffer(GLuint *id, int size, void *data, GLenum region);
void defineVAOAttribute(const GLuint *vao_id, int attribute_index, int attribute_size, int offset, GLenum attribute_type, GLenum normalized);
void attachEBOToVAO(const GLuint *vao_id, const GLuint *vbo_id, const GLuint *ebo_id, int binding_index, int offset, int stride);