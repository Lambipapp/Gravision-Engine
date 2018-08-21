#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "App.h"

#define GLEW_STATIC

extern App* GetApplication();

int main(int argc, char** argv)
{
	int w = 800;
	int h = 600;
	App *app = GetApplication();
	if (!glfwInit())
	{
		return -1;
		// Initialization failed
	}

	GLFWwindow* appWindow = glfwCreateWindow(w, h, "Gravision", NULL, NULL);
	if (!appWindow)
	{
		glfwTerminate();
		return -1;
		// Window or OpenGL context creation failed
	}
	glfwMakeContextCurrent(appWindow);
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		return -1;
	}

	fprintf(stdout, "Status: Using GL %s\n", glGetString(GL_VERSION));
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	fprintf(stdout, "Status: Using GLFW %s\n", glfwGetVersionString());

	app->InitGraphics();
	while (!glfwWindowShouldClose(appWindow))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(appWindow);

		/* Poll for and process events */
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}