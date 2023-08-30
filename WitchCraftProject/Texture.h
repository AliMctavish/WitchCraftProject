#pragma once
#include "Shader.h"

static int _texutreCounter;

class Texture {
private:
	int width, height, nrChannels;
	unsigned int _texture;
	int _textureIndex;
public:
	void Init();
	void Bind();
	void SetTexutre(std::string fileName);
	Texture(const char* fileName, int type);
	const inline unsigned int GetTextureId() { return _texture; }
	~Texture();
};
