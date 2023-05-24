/**
 *@author Sari Safe
 *@since 15.05.23
 */
// to dont include the header alot, once at most
#ifndef COWBOY_H

#define COWBOY_H

#include "Character.hpp"
#include <string>
#include <stdio.h>
#include <iostream>

using std::to_string;

namespace ariel
{

    class Cowboy : public Character
    {
    private:
        int _hitPoints;
        int number_of_boolts;

    public:
        // ctor
        Cowboy(string, Point);
        //  methods
        void shoot(Character *player);
        bool hasboolets();
        void reload();
        string print() override;

    };

};
#endif