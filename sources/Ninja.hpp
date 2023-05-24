#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Character.hpp"
using namespace ariel;
namespace ariel
{
    class Ninja: public Character
    {
        protected:
            int _speed;

        public:
            Ninja(string name, Point location, int hitPoint, int speed);
            
            const int getSpeed() const;
            void setSpeed(int speed);

            void move(Character *other);
            void slash(Character *other);
            string print() const override;

    };
}