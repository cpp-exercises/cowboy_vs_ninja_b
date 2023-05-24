
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
            return "C :[(name :" + this->_name + ", location : " + this->getLocation().print() +" number of hits : " + to_string(health_Points) + "]";
        }
        return "C :[(name :" + this->_name + ", location : " + this->getLocation().print()  + "health" + to_string(health_Points) + "]";
    }

    void Cowboy::shoot(Character *player)
    {
        if (this->number_of_boolts == 0)
        {

            throw std::runtime_error("there no boolts ");
        }
        if (this == player)
        {
            throw std::runtime_error("cannot shoot my self ");
        }
        if ((player->isAlive()) && (this->isAlive()) && (this->number_of_boolts != 0))
        {
            // need to decrease from the oppenet health
            player->hit(10);
            // decreas the boolts
            number_of_boolts -= 1;
        }
        if (!(this->isAlive()))
        {
            // im dead how i can shoot ?!!
            throw std::runtime_error("im dead  ");
        }
    }

    bool Cowboy::hasboolets()
    {
        if (this->number_of_boolts <= 0)
        {
            return false;
        }
        return true;
    }

    void Cowboy::reload()
    {
        if (isAlive())
        {
            this->number_of_boolts = 6;
        }
        throw std::runtime_error(" isnot alive there no need ");
    }

};