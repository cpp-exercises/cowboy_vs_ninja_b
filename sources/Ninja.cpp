

#include "Ninja.hpp"

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using namespace ariel;

Ninja::Ninja(string name, Point point, int health, int speed) : Character(name, point)
{

    // by default
    this->_speed = speed;
    this->health_Points = health;
    this->_sort = 2;
}

Ninja ::Ninja() {}

void Ninja::slash(Character *player)
{

    if (this->health_Points <= 0)
    {

        throw std::runtime_error("im dead ");
    }

    if (this == player)
    {
        throw std::runtime_error("cannot slash your self ");
    }

    if (player->isAlive() == false)
    {
        // im dead how i can shoot ?!!
        throw std::runtime_error("cannot slash dead player ");
    }

    if (this->getLocation().distance(player->getLocation()) <= 1)
    {
        player->hit(40);
    }
}

void Ninja::move(Character *other_player)
{
    this->_location = this->_location.moveTowards(this->_location, other_player->getLocation(), this->_speed);
}

string Ninja::print()
{
    if (isAlive())
    {
        return "N:[( " + this->_name + ", " + this->getLocation().print() + "number of hits " + to_string(this->health_Points) + " )]";
    }
    return "N:[( " + this->_name + ", " + this->getLocation().print() + " )]";
}
