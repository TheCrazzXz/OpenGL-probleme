#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>

#include <fstream>
#include <sstream>

#include "Display.hpp"
#include "GLErrorHandler.hpp"
#include "Camera.hpp"

void prepare();
void render(Camera cam, float rotate);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void setCameraMoveValue(int value)
{
	MoveValue = value;
}


int main(int argc, char **argv)
{
    GLFWwindow* window;
	

    /* Initialize the library */
    if (!glfwInit())
        return -1;
	
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(Display::width, Display::height, "Window", NULL, NULL);

	glfwSetKeyCallback(window, key_callback);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
	
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	
	//glfwSwapInterval(60);
	
	if(glewInit() != GLEW_OK)
	{
		std::cerr << "Erreur : Imposiible d'initialiser GLEW :(" << std::endl;
	}
	std::cout << "OpenGL version : " << glGetString(GL_VERSION) << std::endl;
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		/*prepare*/
		Camera cam{vec3{0, 0, 0}};
		cam.setPerspectiveProjection(70.0f, 0.1f, 1000.0f);

		float rotate = 0;

		prepare();

		/* Boucle principale */
		while (!glfwWindowShouldClose(window))
		{
			std::cout << cam.getPosition().getX() << "/" << cam.getPosition().getY() << "/" << cam.getPosition().getZ() << std::endl;

			rotate += 0.1f;

			/* Rendus ici : */
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			render(cam, rotate);

			cam.move(MoveValue);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
			
		}
	}
    glfwTerminate();
    return 0;
}

void render(Camera cam, float rotate)
{
	cam.getPerspectiveProjection();
	cam.update();

	//glRotatef(rotate, 0.0f, 1.0f, 0.0f);  

	//glPushMatrix();

	glBegin(GL_QUADS);

		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-1, 0.5f, -1);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(1, 0.5f, -1);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1, 0.5f, -3);

		glVertex3f(-1, 0.5f, -3);

	glEnd();

	glBegin(GL_QUADS);

		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-1, -0.5f, -1);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(1, -0.5f, -1);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1, -0.5f, -3);

		glVertex3f(-1, -0.5f, -3);

	glEnd();

	//glPopMatrix();

}
void prepare()
{
	
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_UP)
	{
		setCameraMoveValue(1);
	}
	if(key == GLFW_KEY_DOWN)
	{
		setCameraMoveValue(2);
	}

	else 
	{
		setCameraMoveValue(2);
	}
}


