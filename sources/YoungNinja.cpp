
#include "YoungNinja.hpp"
namespace ariel
{

    YoungNinja::YoungNinja(string name, Point point) : Ninja(name, point)
    {
        this->_speed = 14;
        this->_health = 100;
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
        int value_bool = (int)_inAlive;
        return "YoungNinja :[( " + this->_name + ", " + this->getLocation().print() + ", " + "Alive :" + to_string(value_bool) + ")]";
    }
    void YoungNinja::hit(int damage)
    {
        if (damage < _health)
        {
            _health -= damage;
        }
        _health -= damage;
        this->_inAlive = false;
    }
    void YoungNinja::setName(string name)
    {
        this->_name = name;
    }
    void YoungNinja::slash(Character *player)
    {
        if (this->_health <= 0)
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
};