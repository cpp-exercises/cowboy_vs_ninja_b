//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_NINJA_HPP
#define CPP_EX4_PARTA_NINJA_HPP

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    protected:
        int speed;

    public:
        Ninja(string Name, Point location);
        string print() const override;
        virtual void move(Character *enemy) = 0;
        void slash(Character *enemy);
    };
}

#endif // CPP_EX4_PARTA_NINJA_HPP
