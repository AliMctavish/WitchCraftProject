#version 330 core

//out vec4 color;
out vec4 color;
in  vec3 ourColor;
in vec2 ourTexture;
in float ourTexIndex;

uniform vec4 colorTest;
uniform sampler2D textureFrag[4];
uniform vec4 distance_color;

void main()
{
	int index = int(ourTexIndex);
	//color = vec4(ourTexIndex, ourTexIndex, ourTexIndex, 1.0);
	color = texture(textureFrag[index], ourTexture);
	//color = distance_color;
}