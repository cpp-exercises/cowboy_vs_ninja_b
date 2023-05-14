//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_POINT_HPP
#define CPP_EX4_PARTA_POINT_HPP

namespace ariel
{
    class Point
    {
    private:
        // The location of the point represeted by x and y
        double x_axis, y_axis;
    public:
        // Initializer constructor that take x and y as arguments
        Point(double new_x, double new_y);
        // distance between this object and other
        double distance(const Point &other);
        void print() const;
        static Point moveTowards(const Point &src, const Point &dest, double dist);
        double getX() const;
        double getY() const;
    };
}

#endif // CPP_EX4_PARTA_POINT_HPP
