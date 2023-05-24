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
class Ninja : public Character
{
    // Interface(Abstract class
    // with pure virtual function)
protected:
    // data member's
    int _speed;

public:
    Point _point;
    // ctor
    Ninja(const string &name, Point point, int health, int speed);

    // default ctor
    Ninja() = default;
    /* move to the enemy location*/
    void move(Character *other_player);
    /* attack the enemy */
    void slash(Character *player);

    string print();
};

#endif // NINJA_HPP