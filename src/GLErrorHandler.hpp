#include <iostream>

#if !defined(__GL_ERROR_HANDLER__)
#define __GL_ERROR_HANDLER__

#define ASSERT(x) if(!x) std::cin.ignore();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__));

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

#endif
