//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_YOUNG_NINJA_HPP
#define CPP_EX4_PARTA_YOUNG_NINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
        public:
        YoungNinja(string Name, Point location);
        void move(Character* enemy) override;
    };
}

#endif //CPP_EX4_PARTA_YOUNG_NINJA_HPP
