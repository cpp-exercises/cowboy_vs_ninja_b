/**
 *@author Sari Safe
 *@since 05.05.23
 */

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>

using std::string;
using std::to_string;
namespace ariel
{
    class Point // NOLINT
    {
    private:
        // cordinates for Piont
        double _x;
        double _y;

    public:
        // ctor
        Point(double, double); // NOLINT

        // default ctor
        Point();

        // properties
        double distance(const Point &) const;
        //  print properties
        string print();

        // some point on line
        // with distance tow points src and dest, opreation move to .

        static Point moveTowards(Point, Point, double);

        double getx();
        double gety();
    };

};
#endif // POINT_HPP