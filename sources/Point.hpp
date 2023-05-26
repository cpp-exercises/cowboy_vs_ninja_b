#pragma once    
#include <string>
using namespace std;

namespace ariel {
class Point{

protected:
double x;
double y;

public:
Point ();
Point (double numX, double numY);
 Point(const Point& other) ;
double distance (Point checkPoint);
void print();
Point moveTowards (Point destination, double dist);
static Point moveTowards (Point source, Point destination, double dist);
double getX();
double getY();
  ~Point() = default;
    Point& operator=(const Point& other) = default;
    Point(Point&& other) = default;
    Point& operator=(Point&& other) = default;
};
}