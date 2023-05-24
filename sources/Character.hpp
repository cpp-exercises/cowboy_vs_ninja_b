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

//(Abstract class)

class Character
{
protected:
    /// data member's
    string _name;
    Point _location;

public:
    bool _member;
    bool already_Caption;
    int _sort = 0;
    int health_Points = 0;
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
    bool isAlive();
    /**
     * the distance between this and other Character
     * @return double
     */
    virtual double distance(Character *) const;
    virtual string getName();
    virtual Point getLocation();
    virtual string print() = 0;
    virtual void hit(int damage);

    //
    void setName(string new_name);
    // double gethealth();
    void setHealth(int afterShoot);
};

#endif // CHARACTER_HPP