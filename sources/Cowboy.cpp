
#include "Cowboy.hpp"

namespace ariel
{

    Cowboy::Cowboy(string Cowboy_name, Point point) : _name(Cowboy_name), _point(point)
    {
        this->number_of_boolts = 6;
        // after inheritance need to overload relevant health points
        this->_health = 110;
        this->_hitPoints = 0;
    }

    double Cowboy::distance(Character *player) const
    {
        const Point p = (this->_point);
        double dist = player->getLocation().distance(p);
    };

    string Cowboy::getName()
    {
        return this->_name;
    }

    Point Cowboy::getLocation()
    {
        return this->_point;
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

    void Cowboy::hit(int points)
    {
        if (points > number_of_boolts)
        {
            throw std::out_of_range(" they cant hit more than 6 in per shoot ");
        }
        number_of_boolts -= points;
        _hitPoints += points;
    }

    void Cowboy::setName(string new_name)
    {
        _name = new_name;
    }

    void Cowboy::shoot(Character *player)
    {
        if (player->isAlive() && this->_inAlive)
        {
            // need to decrease from the oppenet
            player->setHealth(10);
            number_of_boolts -= 1;
        }
        else if (!(this->_inAlive))
        {
            // nothing to do
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

    // void Cowboy::move(Character *other)
    // {
    // }

};