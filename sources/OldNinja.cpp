
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

    void OldNinja::slash(Character *player)
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