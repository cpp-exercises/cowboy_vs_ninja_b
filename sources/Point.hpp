<<<<<<< HEAD
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
    class Point
    {
    private:
        // cordinates for Piont
        double _x;
        double _y;

    public:
        // ctor
        Point(double, double);

        // default ctor
        Point();

        // properties
        double distance(const Point &) const;
        // void
        string print();

        // getter's (string value's)

        Point moveTowards(Point, Point, double); // ->double -raduis
        double getx();
        double gety();
    };

};
=======
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
    class Point
    {
    private:
        // cordinates for Piont
        double _x;
        double _y;

    public:
        // ctor
        Point(double, double);

        // default ctor
        Point();

        // properties
        double distance(const Point &);
        // void
        string print();

        // getter's (string value's)

        Point moveTwoards(Point, Point); // ->double -raduis
        double getx();
        double gety();
    };

};
>>>>>>> fbc3513b760438cd93c52e48cd49c4a124c172ac
#endif // POINT_HPP