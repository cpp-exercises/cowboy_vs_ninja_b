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
protected:
    // deafult
    int _health = 120;
    bool _inAlive = true;

public:
    bool member = false;
    /**
     * return if Charcater is alive
     * @return bool - true\false
     */
    virtual bool isAlive()
    {
        if (_health > 0)
        {
            _inAlive = true;
            return true;
        }
        _inAlive = false;
        return false;
    }
    /**
     * the distance between this and other Character
     * @return double
     */
    virtual double distance(ariel::Point *) const { return 0; }
    virtual string getName() { return "ariel"; }
    virtual Point getLocation() { return Point(); }
    virtual string print() { return "print"; }
    virtual void hit(int damage) {}
    virtual void setName(string) {}
    virtual double health() { return _health; }
    virtual void setHealth(int afterShoot)
    {
        this->_health -= afterShoot;
    }
};

#endif // CHARACTER_HPP