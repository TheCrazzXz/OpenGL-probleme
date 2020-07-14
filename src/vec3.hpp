class vec3
{
    private:
        float x, y, z;

    public:
        vec3()
        {
            x = 0;
            y = 0;
            z = 0;
        }

        vec3(float _x, float _y, float _z)
        {
            _x = x;
            _y = y;
            _z = z;
        }
        ~vec3(){}

        inline float getX(){ return x; }
        inline float getY(){ return y; }
        inline float getZ(){ return z; }

        inline float setX(float newX){ x = newX; }
        inline float setY(float newY){ y = newY; }
        inline float setZ(float newZ){ z = newZ; }
};