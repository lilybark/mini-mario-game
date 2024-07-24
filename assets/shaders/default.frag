#version 430 core

in vec4 fPos;
in vec3 fNorm;
in vec4 fColor;
in vec2 fTexCoords;
in float fTexID;
in float fTime;

out vec4 color;

void main()
{
    color = fColor;
}

