/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'

class Point2D
{

private:
    float x = 0.0, y = 0.0;

public:
    Point2D(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    Point2D() : x(0), y(0)
    {
    }

    float getX()
    {
        return x;
    }

    float getY()
    {
        return y;
    }

    void setX(float x)
    {
        this->x = x;
    }

    void setY(float y)
    {
        this->y = y;
    }

    void setXY(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    array<float, 2> getXY()
    {
        return {x, y};
    }
    virtual string toString()
    {
        ostringstream ss;
        ss << "(" << this->x << "," << this->y << ")";
        return ss.str();
    }
};
class Point3D : public Point2D
{
private:
    float z = 0.0;

public:
    Point3D(float x, float y, float z) : Point2D(x, y), z(z)
    {
    }

    Point3D() : Point2D(0, 0), z(0)
    {
    }

    float getZ()
    {
        return z;
    }

    void setZ(float z)
    {
        this->z = z;
    }

    void setXYZ(float x, float y, float z)
    {
        this->setXY(x, y);
        setZ(z);
    }

    array<float, 3> getXYZ()
    {
        return {getX(), getY(), z};
    }

    string toString() override
    {
        ostringstream ss;
        ss << "(" << getX() << "," << getY() << "," << getZ() << ")";
        return ss.str();
    }
};