/**
 *@author Sari Safe
 *@since 15.05.23
 */
// to dont include the header alot, once at most
#ifndef NINJA_H
#define NINJA_H

#include "Character.hpp"
#include <iostream>
#include <string>
using std::string;
using namespace ariel;

// using namespace ariel;
class Ninja
{
    // Interface(Abstract class
    // with pure virtual function)
protected:
    // data member's
    int _speed;
    Point _location;
    string _name;

public:
    // ctor
    Ninja(string name, Point point) : _location(point)
    {
        this->_name = name;
        // by default
        this->_speed = 0;
    }
    // default ctor
    Ninja() : _location(Point()) { this->_name = "default ninja "; }
    /* move to the enemy location*/
    virtual void move(Character *player) {}
    /* attack the enemy */
    virtual void slash(Character *player) {}
    virtual bool isAlive()
    {
        return true;
    }
};

#endif // NINJA_HPP