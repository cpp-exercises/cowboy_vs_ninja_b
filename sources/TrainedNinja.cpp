

#include "TrainedNinja.hpp"

using std::string;
namespace ariel
{
    TrainedNinja::TrainedNinja(string name, Point point) : Ninja(name, point, 150, 8)
    {
        this->health_Points = 120;
        this->_speed = 12;
        this->_name = name;
    }

    // string TrainedNinja::print()
    // {
    //     int value_bool = (int)inAlive;
    //     return "YoungNinja :[( " + this->_name + ", " + this->getLocation().print() + ", " + "Alive :" + to_string(value_bool) + ")]";
    // }

    // void TrainedNinja::slash(Character *player)
    // {
    //     if (!(this->isAlive()))
    //     {

    //         throw std::runtime_error("im dead ");
    //     }
    //     else if (this == player)
    //     {
    //         throw std::runtime_error("cannot slash my self ");
    //     }
    //     else if (!(player->isAlive()))
    //     {
    //         // im dead how i can shoot ?!!
    //         throw std::runtime_error("cannot slash dead player ");
    //     }
    //     else
    //     {
    //         player->hit(40);
    //     }
    // }

    // void TrainedNinja::move(Character *other_player)
    // {

    //     Point location_otherp = other_player->getLocation();
    //     this->_point.moveTowards(this->getLocation(), location_otherp, this->_speed);
    // }
};