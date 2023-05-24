
#include "Cowboy.hpp"

namespace ariel
{

    Cowboy::Cowboy(string Cowboy_name, Point point) : Character(Cowboy_name, point)
    {
        this->number_of_boolts = 6;
        // after inheritance need to overload relevant health points to relevant type
        this->_health = 110;
        // update the type of character after its definded to be Cowboy
        this->_sort = 1;
    }

    string Cowboy::print()
    {
        int value_bool = (int)this->_inAlive;
        if (_inAlive)
        {
            return "C :[(name :" + this->_name + ", location : " + this->getLocation().print() + ", isAlive : " + to_string(value_bool) + " number of hits : " + to_string(_hitPoints) + "]";
        }
        return "C :[(name :" + this->_name + ", location : " + this->getLocation().print() + ", isAlive : " + to_string(value_bool) + "]";
    }

    void Cowboy::shoot(Character *player)
    {
        if (this->number_of_boolts == 0)
        {

            throw std::runtime_error("there no boolts ");
        }
        else if (this == player)
        {
            throw std::runtime_error("cannot shoot my self ");
        }
        else if ((player->isAlive()) && (this->_inAlive) && (this->number_of_boolts != 0))
        {
            // need to decrease from the oppenet health
            player->setHealth(10);
            // decreas the boolts
            number_of_boolts -= 1;
        }
        else if (!(this->_inAlive))
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