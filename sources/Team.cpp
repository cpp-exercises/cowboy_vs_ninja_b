

#include "Team.hpp"

#include <vector>
using namespace ariel;

Team::Team(Character *caption) : leader(caption)
{
    this->_members.push_back(caption);
}

void Team::add(Character *palyer)
{
    if (palyer->member == true)
    {
        throw std::runtime_error(" aleardy in the team ");
    }
    else if (this->_members.size() == 10)
    {
        throw std::runtime_error(" its full team ");
    }
    else
    {
        this->_members.push_back(palyer);
        palyer->member = true;
    }
}
bool Team::stillAlive() { return false; }
void Team::print() {}
void Team::attack(Team *clans) {}
