#version 330 core
out vec4 FragColor;

in vec3 LightingColor; 
in vec2 TexCoord;

uniform vec3 objectColor;
uniform sampler2D texture1;

void main()
{
   FragColor = vec4(LightingColor * vec3(texture(texture1, TexCoord)), 1.0);
}