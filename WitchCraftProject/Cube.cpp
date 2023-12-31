﻿#include "Cube.h"

int Cube::draw_type = DrawTypes::Tringles;

void Cube::Init()
{
	_position = glm::vec3(0, 0, 0);
	_model = glm::mat4(1.0f);
	move_amount = 0;
}

glm::vec3 Cube::GetPosition()
{
	return _position;
}

Cube::Cube(glm::vec3 position)
{
	this->Init();
	_model = glm::mat4(1.0f);
	_position = position;
	_model = glm::translate(_model, _position);
}
void Cube::Rotate(float angle, glm::vec3 side)
{
	_model = glm::rotate(_model, glm::radians(angle), side);
}

void Cube::Transform(glm::vec3 position)
{
	_model = glm::translate(_model, position);
}

void Cube::Oscillate()
{
	_model = glm::translate(_model, glm::vec3(0, sin(move_amount += 0.001f) * 0.001f, 0));
}

void Cube::Update(unsigned int& shader_program)
{
	int modelLoc = glGetUniformLocation(shader_program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(_model));
	glDrawArrays(draw_type, 0, 36 * 309320);
}


Cube::~Cube()
{

}
