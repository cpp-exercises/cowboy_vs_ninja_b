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

    double Point::distance(const Point &other) const
    {
        double dx = _x - other._x;
        double dy = _y - other._y;

        return sqrt(pow(dx,2)+pow(dy,2));
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
        double curr_distance = point0.distance(point1);

        // if (distance == curr_distance)
        // {
        //     // if there tow charcters on the same point we want to  move them apart by an epsilon radius
        //     // double epsil = std::numeric_limits<double>::epsilon();
        //     // return Point(point1._x - epsil, point1._y - epsil);
        //     return point1;//point 0
        // }

        // https://www.wikihow.com/Find-Scale-Factor
        double scalingFactor = distance / curr_distance;
        // new coordinates
        double dx = point1._x - point0._x;
        double dy = point1._y - point0._y;
        double new_x = point0._x + dx * scalingFactor;
        double new_y = point0._y + dy * scalingFactor;
        return Point{new_x, new_y};
    }
    double Point::getx() { return _x; }
    double Point::gety() { return _y; }

}