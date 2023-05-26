#pragma once
#include <string>
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"
#include <vector>


using namespace std;

namespace ariel
{
class Team{
protected:
    Character *leader;

public:
std :: vector <Character*> warriors;
Team (Character* first);
Character* findAnewLeader();
int numOfWarriors;
virtual void add(Character* other );
virtual void attack(Team* enemy);
virtual int stillAlive() const;
void print();
// Character*  findNextToAttack(Team* enemy) ;
Character* findVictim(Team *enemy);
Character* getLeader();
void setLeader(Character* newLeader);
~Team();
//   Team(const Team &other);     // Copy constructor
//     Team(Team &&other) noexcept; // Move constructor
    Team &operator=(const Team &other);
    Team &operator=(Team &&other) noexcept;

};





}



































