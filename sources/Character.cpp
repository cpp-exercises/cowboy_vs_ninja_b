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

// string Character::print() { return "hello"; }

void Character::hit(int damage)
{
    if (damage < health_Points)
    {
        health_Points -= damage;
    }

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

    cout << "here check :" << health_Points << endl;
    return this->health_Points > 0;
}

void Character::setHealth(int afterShoot)
{
    health_Points -= afterShoot;
}

// double Character::gethealth()
// {
//     return health_Points;
// }