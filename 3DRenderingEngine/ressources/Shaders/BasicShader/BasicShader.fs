#version 420 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

void main()
{
    FragColor = vec4( 1.0f * Normal.x, 1.0f * Normal.y, 1.0f * Normal.z, 1.0f);
}