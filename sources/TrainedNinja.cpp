

#include "TrainedNinja.hpp"
// #include "Character.hpp"
// #include "Ninja.hpp"
// #include "Point.hpp"
using std::string;
namespace ariel
{
    TrainedNinja::TrainedNinja(string name, Point point) : Ninja(name, point)
    {
        this->_health = 100;
        this->_speed = 12;
    }

    double TrainedNinja::distance(Character *other) const
    {
        double dis = other->getLocation().distance(this->_location);
        return dis;
    }

    string TrainedNinja::getName()
    {
        return _name;
    }

    Point TrainedNinja::getLocation()
    {
        return this->_location;
    }

    string TrainedNinja::print()
    {
        int value_bool = (int)inAlive;
        return "YoungNinja :[( " + this->_name + ", " + this->getLocation().print() + ", " + "Alive :" + to_string(value_bool) + ")]";
    }

    void TrainedNinja::hit(int damage)
    {
        if (damage < _health)
        {
            _health -= damage;
        }
        _health -= damage;
        this->inAlive = false;
    }

    void TrainedNinja::setName(string name)
    {
        _name = name;
    }

    bool TrainedNinja::isAlive()
    {
        return this->inAlive;
    }
};