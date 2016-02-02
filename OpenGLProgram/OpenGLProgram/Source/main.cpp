#include <gl_core_4_4.h>
#include <glfw3.h>
#include <iostream>

int main()
{
	//initialise glfw services
	if (!glfwInit()) return -1;

	//set up the window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	//load the correct openGL functions for the rendering
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}
	//--------------------------
	//test what version of openGL is being used
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);


	//--------------------------
	//destory the window and terminate glfw services
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}