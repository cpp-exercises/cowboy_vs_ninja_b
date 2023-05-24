

#include "TrainedNinja.hpp"

using std::string;
namespace ariel
{
    TrainedNinja::TrainedNinja(string name, Point point) : Ninja(point), Character(name, point)
    {
        this->_health = 100;
        this->_speed = 12;
        this->_name = name;
    }

    string TrainedNinja::print()
    {
        int value_bool = (int)inAlive;
        return "YoungNinja :[( " + this->_name + ", " + this->getLocation().print() + ", " + "Alive :" + to_string(value_bool) + ")]";
    }

    void TrainedNinja::slash(Character *player)
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