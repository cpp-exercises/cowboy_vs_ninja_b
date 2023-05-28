

#include "Team.hpp"
#include <vector>
#include <cmath>
#include <iostream>
#include <cfloat>
using namespace ariel;

Team::Team(Character *caption)
{
    this->leader = caption;
    // throw if its aleardy the caption in another team
    if (this->leader->already_Caption == true)
    {
        throw std::runtime_error(" im aleary leader in another team ");
    }

    this->leader->_member = true;
    this->leader->already_Caption = true;
    this->clan.push_back(caption);
}

void Team::add(Character *player)
{
    if (!player)
    {
        return;
    }

    if (this->clan.size() >= 10)
    {
        throw std::runtime_error(" its full team !");
    }

    if (player->_member == true)
    {
        throw std::runtime_error(" aleardy in the team ");
    }

    // add them to vector of member's
    clan.push_back(player);
    player->_member = true;
}
// infint loop
int Team::stillAlive()
{
    int amount = 0;
    for (size_t i = 0; i < this->clan.size(); i++)
    {
        if (this->clan.at(i)->isAlive() == true)
        {
            amount += 1;
        }
    }
    return amount;
}
void Team::print()
{
    // print cowboy properties by define  the sort
    for (size_t i = 0; i < this->clan.size(); i++)
    {
        if (this->clan.at(i)->_sort == 1)
        {
            cout << this->clan.at(i)->print() << endl;
        }
    }
    // print ninja properties by define  the sort
    for (size_t i = 0; i < this->clan.size(); i++)
    {
        if (this->clan.at(i)->_sort == 2)
        {
            cout << this->clan.at(i)->print() << endl;
        }
    }
}

Character *Team::closestToMe(Team *team)
{

    // Character *neighbor = nullptr;
    //  maximum distance from leader
    double dist = DBL_MAX;

    // this section to modify
    // the minimum distance from the leader
    size_t i = 0;
    while (i < team->clan.size())
    {
        if (team->clan.at(i)->isAlive() == true && team->clan.at(i)->_sort == 1)
        {
            if (team->clan.at(i)->distance(this->leader) < dist)
                // update the distance
                dist = team->clan.at(i)->distance(this->leader);
        }

        i++;
    }

    i = 0;
    while (i < team->clan.size())
    {
        if (team->clan.at(i)->isAlive() == true && team->clan.at(i)->_sort == 2)
        {
            if (team->clan.at(i)->distance(this->leader) < dist)
            {
                // update the distance
                dist = team->clan.at(i)->distance(this->leader);
            }
        }

        i++;
    }

    // this siction to get this character that have
    // minimum distance from the leader

    i = 0;
    while (i < team->clan.size())
    {

        if (team->clan.at(i)->isAlive() == true && team->clan.at(i)->_sort == 1)
        {
            if (team->clan.at(i)->distance(this->leader) == dist)
            {
                // neighbor = team->clan.at(l);
                return team->clan.at(i);
            }
        }

        i++;
    }

    i = 0;
    while (i < team->clan.size())
    {
        if (team->clan.at(i)->isAlive() == true && team->clan.at(i)->_sort == 2)
        {
            if (team->clan.at(i)->distance(this->leader) == dist)
            {
                // neighbor = team->clan.at(l);
                return team->clan.at(i);
            }
        }

        i++;
    }
    return nullptr;
}

void Team::attack(Team *another_Clan)
{
    if (another_Clan == nullptr)
    {
        throw std::invalid_argument("there no one to attack");
    }

    if (this->stillAlive() == 0)
    {
        throw std::invalid_argument("the side attacker  isnot alive ");
    }

    if (another_Clan->stillAlive() == 0)
    {
        throw std::runtime_error(" defender isnot alive ");
    }

    if (another_Clan == this)
    {
        throw std::invalid_argument("there no compition between members of the clan");
    }

    if (this->leader->isAlive() == false)
    {
        this->leader = closestToMe(this);
    }

    //  loop that attaack and have the main logic:
    // here we get the tearget(oppenet) that need to attack
    // deos some valdition that can be sured have alive target
    // and alive team and enemey teamand attack depond on sort :Ninja, Character
    Character *oppenet = this->closestToMe(another_Clan); // this

    for (size_t i = 0; i < this->clan.size(); i++)
    {
        if (another_Clan->stillAlive() == 0)
        {
            return;
        }

        if (oppenet->isAlive() == false)
        {
            // find another oppent is alive to attack
            oppenet = closestToMe(another_Clan);
        }

        // attack Cowboy logic
        if (this->clan.at(i)->_sort == 1)
        {
            Cowboy *c = static_cast<Cowboy *>(this->clan.at(i));
            if (c->isAlive() == false)
            {
                continue;
            }
            if (c->hasboolets() == false)
            {
                c->reload();
            }
            else
            {
                c->shoot(oppenet);
            }
        }
    }

    for (size_t j = 0; j < this->clan.size(); j++)
    {
        if (another_Clan->stillAlive() == 0)
        {
            return;
        }

        if (oppenet->isAlive() == false)
        {
            // find the closest and then attack
            oppenet = closestToMe(another_Clan);
        }
        // need to extract the ninja's
        if (this->clan.at(j)->_sort == 2)
        {
            Ninja *c = static_cast<Ninja *>(this->clan.at(j));

            if (c->isAlive() == false)
            {
                continue;
            }

            if (c->distance(oppenet) <= 1)
            {
                c->slash(oppenet);
            }

            else
            {
                c->move(oppenet);
            }
        }
    }
}

