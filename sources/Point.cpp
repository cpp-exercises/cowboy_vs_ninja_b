/**
 * declare about implemention and logic of the structure  program
 * :url's tutorial:
 * https://en.cppreference.com/w/
 * https://cplusplus.com/reference/cmath/
 *@author Sari Safe
 *@since 15.05.23
 */

#include "Point.hpp"

using std::cout;
using std::endl;
// using std::to_string;
namespace ariel
{
    //  ctor
    Point::Point(double ix, double iy) : _x(ix), _y(iy)
    {
    }

    // default ctor
    Point::Point() : _x(0), _y(0)
    {
    }

    double Point::distance(const Point &other)
    {

        double dx = _x - other._x;
        double dy = _y - other._y;
        return sqrt(dx * dx + dy * dy);
    };

    string Point::print()
    {

        string temp = "( " + to_string(_x) + ", " + to_string(_y) + ")";
        return temp;
    }
    Point Point::moveTwoards(Point point1, Point point) { return Point(); }
    double Point::getx() { return 0; }
    double Point::gety() { return 0; }

}