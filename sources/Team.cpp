

#include "Team.hpp"

#include <vector>
using namespace ariel;

Team::Team(Character *caption) : leader(caption)
{
    this->_members.push_back(caption);
}

void Team::add(Character *palyer)
{
    this->_members.push_back(palyer);
}
bool Team::stillAlive() { return false; }
void Team::print() {}
void Team::attack(Team *clans) {}
