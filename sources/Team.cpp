#include "Team.hpp"

using namespace std;
using namespace ariel;

Team::Team(Character *leader) : _leader(leader)
{
    add(_leader);
    if(_leader->_captain)
    {
        throw runtime_error("already a captain");
    }
    else
    {
        _leader->_captain=true;
    }
    
}

Team::Team(Team &&other) noexcept : _leader(other._leader), _members(move(other._members))
{
	other._leader = nullptr;
}


Team::~Team()
{
    for (Character *member : _members)
    {
        delete member;
    }

	_members.clear();
}

void Team::add(Character *member)
{
    if (member->_teamate)
    {
        throw runtime_error("already a teamate");
    }
    if (member != nullptr)
    {

        if (_members.size() >= 10)
        {
            throw runtime_error("Team is full");
        }
        else
        {
            _members.push_back(member);
            member->_teamate = true;
        }
        
    }
    else
    {
        throw invalid_argument("Null Value");
    }
}

int Team::stillAlive() const
{
    int count = 0;

	for (Character *member : _members)
	{
		if (member->isAlive())
		{
            cout << "***" << member->getHitPoint() << count << "***" << endl;
            count++;
        }
	}
    cout << "$$$$" << count << endl;
	return count;
}


Character *Team::getVictim(Team *other) const
{
	Character *victim = nullptr;
	double minDistance = 1000000000;

	for (auto member : other->_members)
	{
		if (member->isAlive() && _leader->distance(member) < minDistance)
		{
			minDistance = _leader->distance(member);
			victim = member;
		}
	}

	cout << "Victim is " << victim->getName() << endl;

	return victim;
}

void Team::attack(Team *other)
{
    if (other==nullptr)
    {
        throw invalid_argument("Null Value");
    }

    if (other==this)
    {
        throw runtime_error("Self-Attack is not possible");
    }	
	else if (stillAlive() == 0)
    {
        throw runtime_error("team is dead, and inactive 1");
    }
	else if (other->stillAlive() == 0)
    {
        throw runtime_error("team is dead, and inactive 2");
    }
    else
    {
        if (_leader->isAlive() == false) // if leader is dead, picking a new leader 
        {
            Character *newLeader = nullptr;
            double minDistance = 1000000000;

            for (auto member : _members)
            {
                if (member->isAlive()==true && member->distance(_leader)<minDistance)
                {
                    minDistance = member->distance(_leader);
                    newLeader = member;
                }
            }

            cout << "Dead Leader: " << _leader->getName() << ", New Leader: " << newLeader->getName() << endl;
            _leader = newLeader;

            //now we have a new , alive leader
            //and a new victim
        }

        //start the attack part in the code here
        cout << "Attacker Team: " << _leader->getName() << ", Victim Team: " << other->_leader->getName() << endl;

        // find the victim of the attacker team
        Character *victim = getVictim(other);
        //int cc = 0;
        //int len = 0;
        int c  = 0;

        while (c<2)
        {
            for(Character *member : _members)
            {
                if (!victim->isAlive()) //if the victim is dead, we pick a new one
                {
                    if (other->stillAlive() == 0)
                        break;

                    victim = getVictim(other);
                    //cc++;
                }

                if(c == 0)
                {
                    //Cowboys attacking
                    Cowboy *c = dynamic_cast<Cowboy *>(member);

                    if (c != nullptr && c->isAlive()) // if CowBoy
                    {
                        if (c->hasboolets())
                        {
                            c->shoot(victim);
                        }
                        else
                        {
                            c->reload();
                        }
                    }
                }
                else if (c == 1)
                {
                    //Ninja attacking
                    Ninja *n = dynamic_cast<Ninja *>(member); 

                    if (n != nullptr && n->isAlive()) 
                    {
                        if (n->getLocation().distance(victim->getLocation()) <= 1)
                        {
                            n->slash(victim);
                        }
                        else
                        {
                            n->move(victim);
                        }
                    }
                }
            }
            c++;
        }
    }
}

void Team::print() const
{
    cout << "(Team) TeamLead: " << _leader->getName() << endl;
    int count = 0;

    while (count <2)
    {
        count++;
        for (Character *member : _members)
        {
            if(count == 0 && dynamic_cast<Cowboy *>(member) != nullptr)
            {
                cout << member->print() << endl;
            }
            else if(count == 1 && dynamic_cast<Ninja *>(member) != nullptr)
            {
                cout << member->print() << endl;
            }
        }
    }
}

