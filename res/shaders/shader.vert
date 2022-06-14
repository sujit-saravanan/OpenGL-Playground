#version 450 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uvs;
out vec2 UVs;

uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * vec4(pos.x, pos.y, pos.z, 1.000);
    UVs = uvs;
}