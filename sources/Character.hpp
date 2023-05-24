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
    int _health = 0;
    bool _inAlive;
    int _sort = 0;
    bool _member;

public:
    // ctor
    Character(const string &, Point);
    // default
    Character();
    bool member = false;
    /**
     * return if Charcater is alive
     * @return bool - true\false
     */
    bool isAlive();
    /**
     * the distance between this and other Character
     * @return double
     */
    double distance(Character *) const;
    string getName();
    Point getLocation();
    string print();
    void hit(int damage);

    //
    void setName(string new_name);
    double health();
    void setHealth(int afterShoot);
};

#endif // CHARACTER_HPP