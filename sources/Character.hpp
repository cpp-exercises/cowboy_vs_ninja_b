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

class Character
{
protected:
    /// data member's
    string _name;    // NOLINT
    Point _location; // NOLINT

public:
    bool _member;
    bool already_Caption;
    // 1-> Cowboy
    // 2-> Ninja
    int _sort = 0;
    int health_Points = 0;// NOLINT
    // ctor
    Character(const string &, Point);
    // default
    Character();
    // virtual ctor
    virtual ~Character() = default;

    /**
     * return if Charcater is alive
     * @return bool - true\false
     */
    virtual bool isAlive();
    /**
     * the distance between this and other Character
     * @return double
     */
    virtual double distance(Character *);
    virtual string getName();
    virtual Point getLocation();
    virtual string print() = 0;
    virtual void hit(const int damage);

    //
    void setName(string new_name);
    double gethealth();
};

#endif // CHARACTER_HPP