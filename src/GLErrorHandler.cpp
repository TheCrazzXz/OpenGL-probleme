#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GLErrorHandler.hpp"

#include <iostream>

void GLClearError()
{
	while(glGetError() != GL_NO_ERROR);
}
bool GLLogCall(const char* function, const char* file, int line)
{
	while(GLenum error = glGetError())
	{
		std::cerr << "[OpenGL Error] (" << "File : " << file << ":" << line << " | Error : " << error << ")" << " at : " << "\n" << function << std::endl;
		return false;
	}
	return true;
}