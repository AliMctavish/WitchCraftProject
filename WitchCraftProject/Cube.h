#pragma once
#include "Shader.h"
#include "GlmIncludes.h"


class Cube {
private :
	glm::vec3 _position;
	glm::mat4 _model;
	float _move_amount;
public :
	Cube(glm::vec3 position);
	void Init();
	void Update(unsigned int& shader_program);
	void Rotate(float angle, glm::vec3 side);
	void Transform(glm::vec3 position);
	void Oscillate();
	const inline void SetOscillateValue(float moveAmount) { _move_amount = moveAmount; }
	glm::vec3 GetPosition();
	~Cube();
};
