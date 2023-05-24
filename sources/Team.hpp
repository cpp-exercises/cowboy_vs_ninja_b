/**
 *
 *@author Sari Safe
 *@since 15.05.23
 */

#ifndef TEAM_H
#define TEAM_H

#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>
#include <iostream>
#include <cmath>
using std::vector;

namespace ariel
{

    class Team
    {

    public:
        vector<Character *> clan;
        Character *leader;

        // ctor
        Team(Character *leader);
        // des-ctor
        virtual ~Team()
        {
            for (size_t i = 0; i < clan.size(); i++)
            {
                delete clan.at(i);
            }
        };
        virtual void add(Character *palyer);
        virtual int stillAlive();
        virtual void print();
        virtual void attack(Team *clans);
    };
};
#endif // TEAM_HPP