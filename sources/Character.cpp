#include "Character.hpp"
using namespace ariel;

Character::Character(const string &name, Point location) : _name(name), _location(location)
{
    // default values that  will change deponed on type of the character
    this->_health = 120;
    this->_inAlive = true;
    this->_sort = 0;
}

Character::Character() //: _name("default version"), _location(Point())
{
}

double Character::distance(Character *other) const
{
    double dis = other->getLocation().distance(this->_location);
    return dis;
}

Point Character::getLocation()
{
    return this->_location;
}

string Character::print() { return "hello"; }

void Character::hit(int damage)
{
    if (damage < _health)
    {
        _health -= damage;
    }

    this->_inAlive = false;
}

void Character::setName(string name)
{
    _name = name;
}

string Character::getName()
{
    return _name;
}
bool Character::isAlive()
{
    if (_health > 0)
    {
        _inAlive = true;
        return true;
    }
    _inAlive = false;
    return false;
}

void Character::setHealth(int afterShoot)
{
    _health -= afterShoot;
}
