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
using std::vector;
namespace ariel
{

    class Team
    {
    private:
        Character *leader;
        vector<Character *> _members;

    public:
        // ctor
        Team(Character *leader);
        void add(Character *palyer);
        bool stillAlive();
        void print();
        void attack(Team *clans);
    };
};
#endif // TEAM_HPP