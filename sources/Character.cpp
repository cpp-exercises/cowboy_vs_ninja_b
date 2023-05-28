#include "Character.hpp"
using namespace ariel;

using std::cout;
using std::endl;

Character::Character(const string &name, Point location) : _name(name), _location(location)
{
    // default values that  will change deponed on type of the character
    this->health_Points = 120;
    this->_sort = 0;
    this->_member = false;
    this->already_Caption = false;
}

Character::Character()
{
}

double Character::distance(Character *other)
{
    // changed from to , because the test demands
    // other->getLocation().distance(this->_location);
      
    return this->_location.distance(other->getLocation());
}

Point Character::getLocation()
{
    return this->_location;
}

// string Character::print() { return "hello"; }

void Character::hit(const int damage)
{
    if (damage < 0)
    {
        throw std::invalid_argument("cant be negative damage ");
    }

    this->health_Points -= damage;
}

void Character::setName(string name)
{
    this->_name = name;
}

string Character::getName()
{
    return this->_name;
}
bool Character::isAlive()
{
    return this->health_Points > 0;
}

double Character::gethealth()
{
    return this->health_Points;
}