#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace ariel;
namespace ariel
{
    class Team
    {      
        public:
            Character *_leader;
            vector<Character *> _members;
            int _size;
            Team(const Team& other);
			Team(Team&& other) noexcept;
            Team(Character *leader);
            ~Team();
            
            void add(Character *member);
            int stillAlive() const;

            virtual void attack(Team *other);
            virtual void print() const;
            virtual Character *getVictim(Team *other) const;

    };
}