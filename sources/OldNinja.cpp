<<<<<<< HEAD

#include "OldNinja.hpp"
// #include "Character.hpp"
// #include "Ninja.hpp"
namespace ariel
{

    OldNinja::OldNinja(string name, Point point) : Ninja(name, point)
    {
        this->_health = 150;
        this->_speed = 8;
    }
    
    double OldNinja::distance(Character *other) const
    {
        double dis = other->getLocation().distance(this->_location);
        return dis;
    };

    string OldNinja::getName()
    {
        return this->_name;
    }
    Point OldNinja::getLocation()
    {
        return this->_location;
    }

    string OldNinja::print() { return "hello"; }

    void OldNinja::hit(int damage)
    {
        if (damage < _health)
        {
            _health -= damage;
        }
        _health -= damage;
        this->_inAlive = false;
    }

    void OldNinja::setName(string name)
    {
        _name = name;
    }

    bool OldNinja::isAlive()
    {
        return this->_inAlive;
    }
=======

#include "OldNinja.hpp"
// #include "Character.hpp"
// #include "Ninja.hpp"
namespace ariel
{

    OldNinja::OldNinja(string name, Point point) : Ninja(name, point)
    {
    }
    double OldNinja::distance(Character *player) const { return 0; };
    string OldNinja::getName() { return _pname; }
    Point OldNinja::getLocation() { return _location; }
    string OldNinja::print() { return "hello"; }
    void OldNinja::hit(int number_hits) {}
    void OldNinja::setName(string name) {}
    bool OldNinja::isAlive() { return true; }
>>>>>>> fbc3513b760438cd93c52e48cd49c4a124c172ac
};