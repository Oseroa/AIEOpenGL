#pragma once

#include <gl_core_4_4.h>
#include <glfw3.h>
#include <iostream>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;

class Application
{
public:
	virtual bool Initialise();
	virtual bool Update();
	virtual void Draw();
	virtual void Shutdown();

	GLFWwindow* GetWindow()
	{
		return window;
	}

private:
	GLFWwindow* window = nullptr;

	mat4 view;
	mat4 projection;

	vec4 white = vec4(1);
	vec4 black = vec4(0, 0, 0, 1);
};