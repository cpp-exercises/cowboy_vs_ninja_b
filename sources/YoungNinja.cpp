
#include "YoungNinja.hpp"
namespace ariel
{

    YoungNinja::YoungNinja(string name, Point point) : Ninja(name, point)
    {
        this->_speed = 14;
        this->health = 100;
    }
    double YoungNinja::distance(Character *other) const
    {
        double dis = other->getLocation().distance(this->_location);
        return dis;
    };
    string YoungNinja::getName()
    {
        return _name;
    }
    Point YoungNinja::getLocation()
    {
        return this->_location;
    }
    // format that decided
    string YoungNinja::print()
    {
        int value_bool = (int)inAlive;
        return "YoungNinja :[( " + this->_name + ", " + this->getLocation().print() + ", " + "Alive :" + to_string(value_bool) + ")]";
    }
    void YoungNinja::hit(int damage)
    {
        if (damage < health)
        {
            health -= damage;
        }
        else(damage >= health)
        {
            health -= damage;
            this->inAlive = false;
        }
    }
    void YoungNinja::setName(string name)
    {
        this->_name = name;
    }
    bool YoungNinja::isAlive()
    {
        return this->inAlive;
    }
};