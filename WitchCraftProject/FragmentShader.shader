#version 330 core

out vec4 color;
in  vec3 ourColor;
in vec2 ourTexture;
in vec2 ourTexture2;

uniform vec4 colorTest;
uniform sampler2D textureFrag;
uniform sampler2D textureFrag2;
uniform vec4 distance_color;

void main()
{
	color = mix(texture(textureFrag , vec2(ourTexture.x , ourTexture.y)) , texture(textureFrag2 , vec2(ourTexture2.x, ourTexture2.y)) , 0.5f);
	//color = distance_color;
}