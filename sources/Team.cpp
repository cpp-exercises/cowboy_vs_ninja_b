

#include "Team.hpp"

#include <vector>
using namespace ariel;

Team::Team(Character *caption) : leader(caption)
{
    this->leader = caption;
    this->clan.push_back(caption);
    this->leader->member = true;
}

void Team::add(Character *palyer)
{
    if (palyer->member == true)
    {
        throw std::runtime_error(" aleardy in the team ");
    }
    if (this->clan.size() == 10)
    {
        throw std::runtime_error(" its full team !");
    }

    // add them to vector of member's
    clan.push_back(palyer);
    palyer->member = true;
}
int Team::stillAlive()
{
    int aliveCount = 0;
    for (size_t i = 0; i < this->clan.size(); i++)
    {
        if (this->clan.at(i)->isAlive() == true)
        {
            aliveCount++;
        }
    }
    return aliveCount;
}
void Team::print() {}
void Team::attack(Team *clans)
{
}
