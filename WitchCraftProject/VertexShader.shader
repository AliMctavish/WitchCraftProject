#version 330 core
layout (location = 0) in vec3 vecPos;
layout (location = 1) in vec2 texCoord;
layout(location = 2) in float texIndex;

uniform float Xoffset;
uniform float Yoffset;
uniform float Zoffset;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 ourColor;
out vec2 ourTexture;
out float ourTexIndex;

void main()
{
gl_Position =  projection * view * model * vec4(vecPos.x + Xoffset,vecPos.y +Yoffset , vecPos.z ,1 + Zoffset);
ourTexture = texCoord;
ourTexIndex = texIndex;
}