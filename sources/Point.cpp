#include "Point.hpp"
#include <cmath>
#include <iostream>

namespace ariel{


Point :: Point  (double numX, double numY)
{
    this->x=numX;
    this->y=numY;
}
Point :: Point(const Point& other) : x(other.x), y(other.y) {};


Point :: Point  ()
{
this->x=0.0;
this->y=0.0;
}

double  Point::distance(Point checkPoint)
{
        double deltaX = checkPoint.x - this->x;
        double deltaY = checkPoint.y - this->y;
        return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

 double Point::getX()
    {
        return x;
    }

    double Point::getY()
    {
        return y;
    }
void Point:: print()
{
    cout << "(" << this->getX() << "," << this->getY()<< ")"<< endl;
    return ;
}

 
Point Point::moveTowards(Point dest, double distance)
{
    if (distance < 0)
    {
        throw std::invalid_argument("cant be negetivee");
    }

    double dx = dest.x - x;
    double dy = dest.y - y;
    double currentDistance = std::sqrt(dx * dx + dy * dy);
    if (currentDistance <= distance)
    {
        return dest;
    }
    double ratio = distance / currentDistance;
    double newX = x + ratio * dx;
    double newY = y + ratio * dy;
    return Point(newX, newY);
}

Point Point::moveTowards(Point src, Point dest, double distance)
{
    if (distance < 0)
    {
        throw std::invalid_argument("ant be negetive");
    }
    double dx = dest.x - src.x;
    double dy = dest.y - src.y;
    double currentDistance = std::sqrt(dx * dx + dy * dy);

    if (currentDistance <= distance)
    {
        return dest;
    }
    else
    {
        double ratio = distance / currentDistance;
        double newX = src.x + ratio * dx;
        double newY = src.y + ratio * dy;
        return Point(newX, newY);
    }
}

}