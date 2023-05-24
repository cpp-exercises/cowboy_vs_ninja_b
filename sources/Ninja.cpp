

#include "Ninja.hpp"

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using namespace ariel;

Ninja::Ninja(const string &name, Point point, int health, int speed)
{

    this->_name = name;
    // by default
    this->_speed = speed;
    this->health_Points = health;
    this->_location = point;
}

void Ninja::slash(Character *player)
{

    if (!(this->isAlive()))
    {

        throw std::runtime_error("im dead ");
    }
    else if (this == player)
    {
        throw std::runtime_error("cannot slash my self ");
    }
    else if (!(player->isAlive()))
    {
        // im dead how i can shoot ?!!
        throw std::runtime_error("cannot slash dead player ");
    }
    else
    {
        player->hit(40);
    }
}

void Ninja::move(Character *other_player)
{

    Point location_otherp = other_player->getLocation();
    this->_point.moveTowards(this->getLocation(), location_otherp, this->_speed);
}

string Ninja::print()
{
    return "N:[( " + this->_name + ", " + this->getLocation().print() + ")]";
}
