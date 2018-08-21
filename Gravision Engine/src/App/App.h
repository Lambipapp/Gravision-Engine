#pragma once
#include <cstdlib>
#include <gravision/gravision.h>


class App
{
protected:
	int height;
	int width;
public:
	virtual const char* GetTitle();
	virtual void InitGraphics();
	virtual void SetView();
	virtual void Deinit();
	virtual void Display();
	virtual void Update();
	virtual void Key(unsigned char key);
	virtual void Resize(int width, int height);
	virtual void Mouse(int button, int state, int x, int y);
	void RenderText(float x, float y, const char *text, void* font = NULL);
	void PerspectiveGL(double fovY, double aspect, double zNear, double zFar);
	
};