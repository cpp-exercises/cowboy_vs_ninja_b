#include "Point.hpp"
#include "math.h"
#include <iostream>
using namespace ariel;

// Initiallize the x and y coordinates
Point::Point(double new_x, double new_y) : x_axis(new_x), y_axis(new_y)
{
}

// Calculating the distance between the class Point and some other Point passed as argument
double Point::distance(const Point &other)
{
    return sqrt(pow(this->x_axis - other.getX(), 2) + pow(this->y_axis - other.getY(), 2));
}

// Printing the point in that form: (x,y) 
void Point::print() const
{
    std::cout << "(" << this->x_axis << "," << this->y_axis << ")" << std::endl;
}

// Return the closet Point to the destination Point that is with distance no longer than dist from the
// the source Point
Point Point::moveTowards(const Point &src, const Point &dest, double dist)
{
    return Point(0, 0);
}

double Point::getX() const{
    return this->x_axis;
}

double Point::getY() const{
    return this->y_axis;
}