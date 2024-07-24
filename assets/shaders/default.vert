#version 430 core

layout (location=0) in vec4 aPos;
layout (location=1) in vec3 aNorm;
layout (location=2) in vec4 aColor;
layout (location=3) in vec2 aTexUV;
layout (location=4) in float aTexID;

out vec4 fPos;
out vec3 fNorm;
out vec4 fColor;
out vec2 fTexUV;
out float fTexID;
out float fTime;

uniform float time;
uniform mat4 projection;
uniform mat4 view;

void main() {
    fPos = projection * view * aPos;
    fNorm = aNorm;

    vec3 lightDir = vec3(cos(time), sin(time), 0.0);
    float lightIntensity = (dot(lightDir, aNorm) + 1.0) / 2.0;

    fColor = vec4(aColor.rgb * lightIntensity, 1.0);
    fTexUV = aTexUV;
    fTexID = aTexID;
    fTime = time;

    gl_Position = fPos;
}

