#include <Application.h>

bool Application::Initialise()
{
	//initialise glfw services
	if (!glfwInit()) return false;

	//set up the window
	window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	//load the correct openGL functions for the rendering
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return false;
	}
	//--------------------------
	/*//test what version of openGL is being used
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);*/

	Gizmos::create();

	view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0)); //where the camera is looking in the world
	projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f); //perspective field of view and 3d perspective V

	//set backgorund clear colour
	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST); //enables depth buffer

	return true;
}

bool Application::Update()
{
	//game loop
	if (glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		return false;
	}
	else
	{
		glfwPollEvents();
	}

	return true;
}

void Application::Draw()
{
	//clears the screen for next frame to draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Gizmos::clear();
	Gizmos::addTransform(glm::mat4(1));

	for (int i = 0; i < 21; i++)
	{
		Gizmos::addLine(vec3(-10 + i, 0, 10), vec3(-10 + i, 0, -10), i == 10 ? white : black);
		Gizmos::addLine(vec3(10, 0, -10 + i), vec3(-10, 0, -10 + i), i == 10 ? white : black);
	}

	Gizmos::draw(projection * view);
	//----------------------
	glfwSwapBuffers(window);
}

void Application::Shutdown()
{
	//destory the window and terminate glfw services
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
}