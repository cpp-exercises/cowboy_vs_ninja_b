
#include "Cowboy.hpp"

namespace ariel
{

    Cowboy::Cowboy(string Cowboy_name, Point point) : Character(Cowboy_name, point)
    {
        this->number_of_boolts = 6;
        // after inheritance need to overload relevant health points to relevant type
        this->health_Points = 110;
        // update the type of character after its definded to be Cowboy
        this->_sort = 1;
    }

    string Cowboy::print()
    {
        if (this->isAlive())
        {
            return "C :[(name :" + this->_name + ", location : " + this->getLocation().print() + " number of hits : " + to_string(health_Points) + "]";
        }
        return "C :[(name :" + this->_name + ", location : " + this->getLocation().print() + "health" + to_string(health_Points) + "]";
    }

    void Cowboy::shoot(Character *player)
    {
        if (this->number_of_boolts == 0)
        {

            return;
        }

        if (this->health_Points <= 0)
        {
            throw std::runtime_error("im dead there no way to shoot ");
        }

        if (this == player)
        {
            throw std::runtime_error("cannot shoot my self ");
        }

        if (player->isAlive() == false)
        {
            // im dead how i can shoot ?!!
            throw std::runtime_error("im dead  ");
        }

        // need to decrease from the oppenet health
        player->hit(10);
        // decreas the boolts
        this->number_of_boolts -= 1;
    }

    bool Cowboy::hasboolets()
    {

        return (this->number_of_boolts > 0);
    }

    void Cowboy::reload()
    {
        if (this->health_Points <= 0)
        {
            throw std::runtime_error(" isnot alive there no need ");
        }
        this->number_of_boolts = 6;
    }

};