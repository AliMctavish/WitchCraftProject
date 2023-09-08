#pragma once
#include "Shader.h"
#include "GlmIncludes.h"

enum DrawTypes {
	Tringles = GL_TRIANGLES,
	Lines = GL_LINES,
	Points = GL_POINTS
};

class Cube {
private:
	glm::vec3 _position;
	glm::mat4 _model;
	float move_amount;
	int draw_type;
public:
	Cube(glm::vec3 position);
	void Init();
	void Update(unsigned int& shader_program);
	void Rotate(float angle, glm::vec3 side);
	void Transform(glm::vec3 position);
	void Oscillate();
	const inline void SetOscillateValue(float moveAmount) { move_amount = moveAmount; }
	const inline void SetDrawType(int type) { draw_type = type; }
	glm::vec3 GetPosition();
	~Cube();
};
