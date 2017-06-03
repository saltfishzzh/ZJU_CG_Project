#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/vec3.hpp> // glm::vec3
#include <GLFW/glfw3.h>


class Character
{
public:
	void move_front();
	void move_back();
	void move_left();
	void move_right();
	const glm::vec3 get_cord()
	{
		return cordinate;
	}
	const GLuint get_hp()
	{
		return health_point;
	}
	const GLuint get_attk()
	{
		return attack;
	}
	Character();
	~Character();
private:
	glm::vec3 cordinate;
	GLuint health_point;
	GLuint attack;
};