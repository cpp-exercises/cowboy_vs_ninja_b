

#include "Team.hpp"
#include <vector>
using namespace ariel;

Team::Team(Character *caption) : leader(caption)
{
    if (leader->already_Caption)
    {
        throw std::runtime_error(" im aleary leader in another team ");
    }
    this->leader = caption;
    this->clan.push_back(caption);
    this->leader->_member = true;
    this->leader->already_Caption = true;
}

void Team::add(Character *player)
{

    if (!player)
    {
        return;
    }

    if (player->_member == true)
    {
        throw std::runtime_error(" aleardy in the team ");
    }

    if (this->clan.size() == 10)
    {
        throw std::runtime_error(" its full team !");
    }

    // add them to vector of member's
    clan.push_back(player);
    player->_member = true;
}
// infint loop
int Team::stillAlive()
{
    int aliveCount = 0;
    for (size_t i = 0; i < this->clan.size(); i++)
    {
        //cout << this->clan.at(i)->getName() << endl;
        if (this->clan.at(i)->isAlive() == false)
        {
            i++;
        }
        aliveCount++;
    }
    return aliveCount;
}
void Team::print() {}

Character *Team::closestToMe(Team *team)
{

    Character *neighbor = nullptr;
    // minimum distance from leader
    double dist = std::numeric_limits<double>::max();

    // this section to modify
    // the minimum distance from the leader
    size_t i = 0;
    size_t n = 0;
    while (i < team->clan.size())
    {
        if (team->clan.at(i)->isAlive() == true && team->clan.at(i)->_sort == 1)
        {
            if (team->clan.at(i)->distance(this->leader) < dist)
                dist = team->clan.at(i)->distance(this->leader);
        }
        i++;
    }

    while (n < team->clan.size())
    {
        if (team->clan.at(n)->isAlive() == true && team->clan.at(n)->_sort == 2)
        {
            if (team->clan.at(i)->distance(this->leader) < dist)
                dist = team->clan.at(n)->distance(this->leader);
        }
        n++;
    }

    // this siction to get this character that have
    // minimum distance from the leader

    size_t j = 0;
    size_t l = 0;

    while (l < team->clan.size())
    {
        if (team->clan.at(l)->isAlive() == true && team->clan.at(l)->_sort == 1)
        {
            if (team->clan.at(l)->distance(this->leader) == dist)
                neighbor = team->clan.at(l);
        }
        l++;
    }

    while (j < team->clan.size())
    {
        if (team->clan.at(j)->isAlive() == true && team->clan.at(j)->_sort == 2)
        {
            if (team->clan.at(j)->distance(this->leader) == dist)
                neighbor = team->clan.at(j);
        }
        j++;
    }

    // return it
    return neighbor;
}

void Team::attack(Team *another_Clan)
{

    if (this->stillAlive() == 0 || another_Clan->stillAlive() == 0)
    {
        throw std::runtime_error("on of the side attacker or defender isnot alive ");
    }

    if (another_Clan == nullptr)
    {
        throw std::invalid_argument("there no one to attack");
    }

    if (this == another_Clan)
    {
        throw std::runtime_error("there no compition between members of the clan");
    }

    if (this->leader->isAlive() == false)
    {
        this->leader = closestToMe(this);
    }

    // the loop that attaack and have the main logic:
    // here we get the tearget(oppenet) that need to attack
    // deos some valdition that can be sured have alive target
    // and alive team and enemey teamand attack depond on sort :Ninja, Character
    Character *oppenet = closestToMe(another_Clan);
    for (size_t i = 0; i < this->clan.size(); i++)
    {
        if (another_Clan->stillAlive() == 0)
        {
            return;
        }
        else
        {
            if (oppenet == nullptr)
            {
                return;
            }
            if (oppenet->isAlive() == false)
            {
                // find another oppent is alive to attack
                oppenet = closestToMe(another_Clan);
            }

            // attack ninja logic
            if (this->clan.at(i)->_sort == 2)
            {
                Ninja *c = static_cast<Ninja *>(this->clan.at(i));
                if (c->isAlive() == false)
                    continue;
                if (c->_point.distance(oppenet->getLocation()) <= 1)
                    c->slash(oppenet);
                else
                    c->move(oppenet);
            }
        }

        // attack Cowboy logic
        if (this->clan.at(i)->_sort == 1)
        {
            Cowboy *c = static_cast<Cowboy *>(this->clan.at(i));
            if (c->isAlive() == false)
                continue;
            if (c->hasboolets() == false)
                c->reload();
            else
                c->shoot(oppenet);
        }
    }
}
