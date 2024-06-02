#version 330 core

layout (location=0) in vec4 aPos;
layout (location=1) in vec4 aColor;
layout (location=2) in vec2 aTexUV;
layout (location=3) in float aTexID;

out vec4 fPos;
out vec4 fColor;
out vec2 fTexUV;
out float fTexID;

uniform mat4 projection;
uniform mat4 view;

void main() {
    fPos = projection * view * aPos;
    fColor = aColor;
    fTexUV = aTexUV;
    fTexID = aTexID;

    gl_Position = fPos;
}

