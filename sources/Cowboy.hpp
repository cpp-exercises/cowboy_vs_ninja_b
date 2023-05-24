#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Character.hpp"
using namespace ariel;
namespace ariel
{
    class Cowboy: public Character
    {
        private:
            int _bullets;

        public:
            Cowboy(string name, Point location);
            
            void shoot(Character *other);
            bool hasboolets() const;
            void reload();
            string print() const override;
    };
}