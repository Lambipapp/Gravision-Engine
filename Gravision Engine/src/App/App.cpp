//#include "App.h"
//#include <GLEW/glew.h>
//#include <GLFW/glfw3.h>
//
//
//
//const char * App::GetTitle()
//{
//	return "Gravision Demo";
//}
//
//void App::InitGraphics()
//{
//	glClearColor(0.9f, 0.95f, 1.0f, 1.0f);
//	glEnable(GL_DEPTH_TEST);
//	glShadeModel(GL_SMOOTH);
//
//	SetView();
//}
//
//void App::SetView()
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	PerspectiveGL(60.0, (double)width / (double)height, 1.0, 500.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void App::Deinit()
//{
//}
//
//void App::Display()
//{
//
//}
//
//void App::Update()
//{
//
//}
//
//void App::Key(unsigned char key)
//{
//}
//
//void App::Resize(int width, int height)
//{
//	// Avoid the divide by zero.
//	if (height <= 0) height = 1;
//
//	// Set the internal variables and update the view
//	App::width = width;
//	App::height = height;
//	glViewport(0, 0, width, height);
//	SetView();
//}
//
//void App::Mouse(int button, int state, int x, int y)
//{
//}
//
//void App::RenderText(float x, float y, const char * text, void * font)
//{
//}
//App * GetApplication()
//{
//	return new App();
//}
//void App::PerspectiveGL(GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar)
//{
//	const GLdouble pi = 3.1415926535897932384626433832795;
//	GLdouble fW, fH;
//
//	//fH = tan( (fovY / 2) / 180 * pi ) * zNear;
//	fH = tan(fovY / 360 * pi) * zNear;
//	fW = fH * aspect;
//
//	glFrustum(-fW, fW, -fH, fH, zNear, zFar);
//}
//
