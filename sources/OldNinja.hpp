//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_OLD_NINJA_HPP
#define CPP_EX4_PARTA_OLD_NINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        public:
        OldNinja(string Name, Point location);
        void move(Character* enemy) override;
    };
}

#endif //CPP_EX4_PARTA_OLD_NINJA_HPP
