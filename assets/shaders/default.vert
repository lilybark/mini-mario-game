#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec4 aColor;
layout (location=2) in vec2 aTexUV;
layout (location=3) in float aTexID;

out vec3 fPos;
out vec4 fColor;
out vec2 fTexUV;
out float fTexID;

void main() {
    fPos = aPos;
    fColor = aColor;
    fTexUV = aTexUV;
    fTexID = aTexID;

    gl_Position = vec4(aPos, 1.0);
}
