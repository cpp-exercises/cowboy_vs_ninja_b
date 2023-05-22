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
        // des ctor
        virtual ~Team()
        {
            for (size_t i = 0; i < _members.size(); i++)
            {
                delete _members.at(i);
            }
        }
        virtual void add(Character *palyer);
        virtual bool stillAlive();
        virtual void print();
        virtual void attack(Team *clans);
    };
};
#endif // TEAM_HPP