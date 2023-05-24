#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point location, int hitPoint, int speed) : Character(name, location, hitPoint)
{
    _speed=speed;
}

const int Ninja::getSpeed() const
{
    return _speed;
}
void Ninja::setSpeed(int speed)
{
    _speed = speed;
}

void Ninja::move(Character *other)
{
    if (other==nullptr)
    {
        throw invalid_argument("Null Value");
    }

    if (other==this)
    {
        throw runtime_error("Self-Hit is not possible");
    }	
	else if (isAlive() != true)
    {
        throw runtime_error("Charecter is dead, and inactive 8");
    }
	else if (other->isAlive() != true)
    {
        throw runtime_error("Charecter is dead, and inactive 9");
    }
    else
    {
        Point newLocation = Point::moveTowards(getLocation(), other->getLocation(), _speed);
	    setLocation(newLocation);

	    cout << getName() << " move to " << other->getName() << endl;
        cout << "distance after move: " << getLocation().distance(other->getLocation()) << endl;
    }
}

void Ninja::slash(Character *other)
{
    if (other==nullptr)
    {
        throw invalid_argument("Null Value");
    }

    if (other==this)
    {
        throw runtime_error("Self-Hit is not possible");
    }	
	else if (isAlive() != true)
    {
        throw runtime_error("Charecter is dead, and inactive 6");
    }
	else if (other->isAlive() != true)
    {
        throw runtime_error("Charecter is dead, and inactive 7");
    }
    else
    {
        if (_location.distance(other->getLocation()) > 1)
        {
            cout << getName() << " distance from " << other->getName() << " is " << getLocation().distance(other->getLocation()) << ". SLASH is not possible" << endl;
        }
        else
        {
            cout << getName() << "slash seccessfuly on " << other->getName() << " with 40 hitPoints." << endl;
            other->hit(40);
        }
    }
}

string Ninja::print() const
{
    if (isAlive() != true)
    {
        return "Name(Ninja): "+getName()+", Location: "+getLocation().print();
    }
		

	return "Name(Ninja): "+getName()+", Location: "+getLocation().print()+", Hit Points: "+to_string(getHitPoint());
}
