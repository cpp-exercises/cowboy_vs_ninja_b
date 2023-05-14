//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_COWBOY_HPP
#define CPP_EX4_PARTA_COWBOY_HPP

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int num_of_bullets;
        
    public:
        Cowboy(string Name, Point location);
        string print() const override;
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
    };
}

#endif // CPP_EX4_PARTA_COWBOY_HPP
