#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GL/glu.h"

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>

#include "vec3.hpp"
#include "Display.hpp"

int MoveValue;

class Camera
{
    public:
        Camera(vec3 _position)
        {
            _position = position;
        }
        ~Camera(){}

        static int MoveValue;

        /* GETTERS/SETTERS */

        vec3 getPosition()
        {
            return position;
        }
        void setPosition(vec3 _position)
        {
            _position = position;
        }

        /* --------------- */

        Camera setPerspectiveProjection(float _fov, float _zNear, float _zFar)
        {
            _fov = fov;
            _zNear = _zNear;
            _zFar = _zFar;

            return *this;
        }
        void getPerspectiveProjection()
        {
            glEnable(GL_PROJECTION);
            glLoadIdentity();

            gluPerspective(fov, float(Display::width) / float(Display::height), zNear, zFar);

            glEnable(GL_MODELVIEW);
        }
        void update()
        {
            glPushAttrib(GL_TRANSFORM_BIT);
                glTranslatef(position.getX(), position.getY(), position.getZ());
            glPopMatrix();
        }
        void move(int MoveValue)
        {
            /*if(MoveValue == 1)
            {
               position.setZ(position.getZ() + 1);
            }
            if(MoveValue == 2)
            {
                position.setZ(position.getZ() - 1);
            }*/
        }

    private:
        float fov;
        float zNear;
        float zFar;
        vec3 position;
};
