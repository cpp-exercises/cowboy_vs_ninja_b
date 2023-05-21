/**
 *@author Sari Safe
 *@since 15.05.23
 */
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Point.hpp"
#include <iostream>
#include <string>
#include <cmath>

using namespace ariel;

// Interface(Abstract class
// with pure virtual function)
class Character
{
public:
    /**
     * return if Charcater is alive
     * @return bool - true\false
     */
    virtual bool isAlive() { return true; }
    /**
     * the distance between this and other Character
     * @return double
     */
    virtual double distance(ariel::Point *) const { return 0; }
    virtual string getName() { return "ariel"; }
    virtual Point getLocation() { return Point(); }
    virtual string print() { return "print"; }
    virtual void hit(int) {}
    virtual void setName(string) {}
    virtual double health() { return 120; }
};

#endif // CHARACTER_HPP