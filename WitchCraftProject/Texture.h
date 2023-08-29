#pragma once
#include "Shader.h"

static int _texutreCounter;

class Texture {
private:
	int width, height, nrChannels;
	unsigned int _texture;
public:
	void Init();
	void SetTexutre(std::string fileName);
	Texture(const char* fileName, int type);
	~Texture();
};
