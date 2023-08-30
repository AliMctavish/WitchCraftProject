#include "Texture.h"
#include "TextureLoader.h"

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + _texutreCounter);
	glBindTexture(GL_TEXTURE_2D, _texture);
}


void Texture::Init()
{
	glGenTextures(1, &_texture);

	glActiveTexture(GL_TEXTURE0 + _texutreCounter);
	glBindTexture(GL_TEXTURE_2D, _texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	_texutreCounter += 1;

	_textureIndex = _texutreCounter;
}

Texture::Texture(const char* fileName , int type)
{
	this->Init();


	stbi_uc* data = stbi_load(fileName, &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_set_flip_vertically_on_load(true);

	stbi_image_free(data);
}

Texture::~Texture()
{
}
