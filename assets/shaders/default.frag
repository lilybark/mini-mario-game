#version 330 core

in vec3 fPos;
in vec4 fColor;
in vec2 fTexCoords;
in float fTexID;

uniform sampler2D uTextures[8];
uniform float uTime;

out vec4 color;

void main()
{
    if (fTexID == 1.0)
    {
        color = fColor * texture(uTextures[0], fTexCoords);
    }
    else if (fTexID == 2.0)
    {
        color = fColor * texture(uTextures[1], fTexCoords);
    }
    else if (fTexID == 3.0)
    {
        color = fColor * texture(uTextures[2], fTexCoords);
    }
    else if (fTexID == 4.0)
    {
        color = fColor * texture(uTextures[3], fTexCoords);
    }
    else if (fTexID == 5.0)
    {
        color = fColor * texture(uTextures[4], fTexCoords);
    }
    else if (fTexID == 6.0)
    {
        color = fColor * texture(uTextures[5], fTexCoords);
    }
    else if (fTexID == 7.0)
    {
        color = fColor * texture(uTextures[6], fTexCoords);
    }
    else if (fTexID == 8.0)
    {
        color = fColor * texture(uTextures[7], fTexCoords);
    }
    else
    {
        color = fColor;
    }

/*
    if (fTexID > 0.0)
    {
        int id = int(fTexID);
        color = fColor * texture(uTextures[id - 1], fTexCoords); // - vignetteConst;
    }
    else
    {
        color = fColor;
    }
*/
}
