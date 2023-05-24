#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#include "Team.hpp"
using namespace ariel;

namespace ariel
{
    class Team2 : public Team
    {   
        public:        
            Team2(Character *leader);
            void attack(Team *other) override;
            void print() const override;
    };
    
    class SmartTeam : public Team
    {    
        public:        
            SmartTeam(Character *leader);
            void attack(Team *other) override;
            void print() const override;
            Character* getStrongestVictim(Team *other) const;

    };
}