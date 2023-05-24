
#include "YoungNinja.hpp"
namespace ariel
{

    YoungNinja::YoungNinja(string name, Point point) : Ninja(point), Character(name, point)
    {
        this->_speed = 14;
        this->_health = 100;
        this->_name = name;
    }

    // format that decided
    string YoungNinja::print()
    {
        int value_bool = (int)_inAlive;
        return "YoungNinja :[( " + this->_name + ", " + this->getLocation().print() + ", " + "Alive :" + to_string(value_bool) + ")]";
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