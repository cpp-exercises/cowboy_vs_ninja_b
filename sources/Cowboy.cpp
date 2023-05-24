#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location,110), _bullets(6)
{

}
//## copy constructor??

void Cowboy::shoot(Character *other)
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
        throw runtime_error("Charecter is dead, and inactive 3");
    }
	else if (other->isAlive() != true)
    {
        throw runtime_error("Charecter is dead, and inactive 4");
    }
    else
    {
        if (_bullets > 0)
        {
            cout << getName() << " shooting " << other->getName() << " 10 hitPoints" << endl;
            _bullets -= 1;
            other->hit(10);
        }
        else
        {
            cout << "no bulltes left for" << getName() << endl;
        }
    }
}

bool Cowboy::hasboolets() const
{
    return (_bullets>0 ? true : false);
}

void Cowboy::reload()
{
    if (isAlive() != true)
    {
        throw runtime_error("Charecter is dead, and inactive 5");
    }
    else
    {
        cout << "reload 6 bullets to: " << getName() << endl;
	    _bullets = 6;
    }
}

string Cowboy::print() const
{
    if (isAlive() != true)
    {
        return "Name(Cowboy): "+getName()+", Location: "+getLocation().print();
    }
		

	return "Name(Cowboy): "+getName()+", Location: "+getLocation().print()+", Hit Points: "+to_string(getHitPoint());
}