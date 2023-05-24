#include "Character.hpp"

using namespace std;
using namespace ariel;

Character::Character(string name, Point location, int hitPoint) : _name(name), _location(location), _hitPoints(hitPoint), _captain(false), _teamate(false)
{

}

string Character::getName() const
{
    return _name;
}

int Character::getHitPoint() const
{
    return _hitPoints;
}

Point Character::getLocation() const
{
    return _location;
}

void Character::setLocation(Point& location)
{
    _location = location;
    return;    
}

bool Character::isAlive() const
{
    return (_hitPoints>0 ? true : false);
}

double Character::distance(Character *other) const
{
    if (other!=nullptr)
    {
        return _location.distance(other->getLocation());
    }
    else
    {
         throw invalid_argument("null character!");
    }	
}

void Character::hit(int amount)
{
    if (amount >= 0)
    {
        if(_hitPoints - amount < 0)
        {
            _hitPoints = 0;
            cout << _name << "is dead, and inactive :(" << endl;
        }
        else
        {
            _hitPoints = _hitPoints - amount;
        }
		
    }
    else
    {
        throw invalid_argument("Hit Points can't be negative");
    }
		
	cout << _hitPoints << "@@@@@@@@@@@" << endl;
}