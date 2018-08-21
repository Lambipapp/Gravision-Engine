#include "App.h"
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>



const char * App::getTitle()
{
	return "Gravision Demo";
}

void App::initGraphics()
{

	if (!glfwInit())
	{
		// Initialization failed
		glfwTerminate();
	}
}

void App::setView()
{

}

void App::deinit()
{
}

void App::display()
{

}

void App::update()
{

}

void App::key(unsigned char key)
{
}

void App::resize(int width, int height)
{

}

void App::mouse(int button, int state, int x, int y)
{
}

void App::renderText(float x, float y, const char * text, void * font)
{
}
