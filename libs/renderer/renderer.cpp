#include "renderer.h"

void generateTexture(texture *tex, const char *texture_path, GLint scaling_type, GLint wrapping_type){
    tex->bytes = stbi_load(texture_path, &tex->width, &tex->height, &tex->channels, 0);

    glCreateTextures(GL_TEXTURE_2D, 1, &tex->id);

    glTextureParameteri(tex->id, GL_TEXTURE_MIN_FILTER, scaling_type);
    glTextureParameteri(tex->id, GL_TEXTURE_MAG_FILTER, scaling_type);
    glTextureParameteri(tex->id, GL_TEXTURE_WRAP_S, wrapping_type);
    glTextureParameteri(tex->id, GL_TEXTURE_WRAP_T, wrapping_type);

    glTextureStorage2D(tex->id, 1, GL_RGBA8, tex->width, tex->height);
    glTextureSubImage2D(tex->id, 0, 0, 0, tex->width, tex->height, GL_RGBA, GL_UNSIGNED_BYTE, tex->bytes);
    glGenerateTextureMipmap(tex->id);
}

void generateVAO(GLuint *id){
    glCreateVertexArrays(1, id);
}
void generateBuffer(GLuint *id, int size, void *data, GLenum region){
    glCreateBuffers(1, id);
    glNamedBufferData(*id, size, data, region);

}
void defineVAOAttribute(const GLuint *vao_id, int attribute_index, int attribute_size, int offset, GLenum attribute_type, GLenum normalized){
    glEnableVertexArrayAttrib(*vao_id, attribute_index);
    glVertexArrayAttribBinding(*vao_id, attribute_index, 0);
    glVertexArrayAttribFormat(*vao_id, attribute_index, attribute_size, attribute_type, normalized, offset);
}
void attachEBOToVAO(const GLuint *vao_id, const GLuint *vbo_id, const GLuint *ebo_id, int binding_index, int offset, int stride){
    glVertexArrayVertexBuffer(*vao_id, binding_index, *vbo_id, offset, stride);
    glVertexArrayElementBuffer(*vao_id, *ebo_id);
}