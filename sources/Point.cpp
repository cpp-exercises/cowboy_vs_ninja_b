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
    Point::Point()
    {
    }

    double Point::distance(const Point &other) const
    {
        double dx = this->_x - other._x;
        double dy = this->_y - other._y;

        return sqrt(pow(dx, 2) + pow(dy, 2));
    };

    string Point::print()
    {

        string temp = "Point :[( " + to_string(_x) + ", " + to_string(_y) + ")]";
        return temp;
    }
    Point Point::moveTowards(Point point0, Point point1, double distance)
    {
        if (distance < 0)
        {
            throw std::invalid_argument("Coannot by negative distance");
        }
        double dx = point1._x - point0._x;
        double dy = point1._y - point0._y;
        double curr_distance = sqrt(pow(dx, 2) + pow(dy, 2));
        if (curr_distance <= distance)
        {
            return point1;
        }
        // https://www.wikihow.com/Find-Scale-Factor
        double scalingFactor = distance / curr_distance;
        // new coordinates

        double new_x = point0._x + dx * scalingFactor;
        double new_y = point0._y + dy * scalingFactor;
        return Point{new_x, new_y};
    }
    double Point::getx() { return _x; }
    double Point::gety() { return _y; }

}