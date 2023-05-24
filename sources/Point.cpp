#include "Point.hpp"

using namespace std;
using namespace ariel;

Point::Point() : _x(0.0), _y(0.0)
{

}

Point::Point(double x, double y) : _x(x), _y(y)
{
    
}

double Point::getX() const
{
    return _x;    
}

double Point::getY() const
{
    return _y;
}

double Point::distance(Point other) const
{
    //implenet distance of formola of distance between 2 points
    
    double p = pow(_x - other.getX(), 2); 
    p +=  pow(_y - other.getY(), 2);
    double res = sqrt(p);

    cout << print() << "&&" << other.print() << res << endl;
    return res;
}

string Point::print() const
{
    return "("+to_string(_x)+","+to_string(_y)+")";
}

const Point Point::moveTowards(const Point &current,const Point &other, double distance)
{
    //std::cout << current.print() << "**" << other.print() << "**" << distance << endl;
    
    if (distance<0)
    {
        throw invalid_argument("distance can't be negative");
        
    }

    double dist = current.distance(other);
    //std::cout << "***DIST COMP****:" << dist << "VS" << current.distance(other) << endl;
    if (dist <= distance)
    {
        return other;
    }
    else
    {
        double ratio = distance / dist;
        double newX = current._x + ratio * (other._x - current._x);
        double newY = current._y + ratio * (other._y - current._y);
        
        //std::cout << "*******" << Point(newX, newY).print() << endl;
        return Point(newX, newY);
    }
}