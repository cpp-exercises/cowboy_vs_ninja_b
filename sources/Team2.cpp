#include "Team2.hpp"

using namespace std;
using namespace ariel;

Team2::Team2(Character *leader) : Team(leader)
{

}

void Team2::attack(Team *other)

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
        throw runtime_error("Charecter is dead, and inactive 10");
    }
	else if (other->stillAlive() == 0)
    {
        throw runtime_error("Charecter is dead, and inactive 11");
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

        for (Character *member : _members)
        {
            if (!victim->isAlive()) //if the victim is dead, we pick a new one
            {
                if (other->stillAlive() == 0)
                    break;

                victim = getVictim(other);
            }
            //now we have new alive victim

            Cowboy* c = dynamic_cast<Cowboy*>(member);

            if (c != nullptr && c->isAlive())
            {
                if (c->hasboolets())
                    c->shoot(victim);

                else
                    c->reload();
            }
            else
            {
                Ninja* n = dynamic_cast<Ninja*>(member);
                if (n != nullptr && n->isAlive())
                {
                    if (n->getLocation().distance(victim->getLocation()) <= 1)
                        n->slash(victim);

                    else
                        n->move(victim);
                }
            }
        }
    }
}


void Team2::print() const
{
    cout << "(Team2)TeamLead: " << _leader->getName() << endl;

	for (Character *member : _members)
    {
        cout << member->print() << endl;
    }		
}

SmartTeam::SmartTeam(Character *leader): Team(leader)
{

}

Character* SmartTeam::getStrongestVictim(Team *other) const
{
	Character *strong = nullptr;
	double stronngest = 0;

	for (auto member : other->_members)
	{
		if (member->isAlive() && _leader->getHitPoint()< member->getHitPoint())
		{
			stronngest = member->getHitPoint();
			strong = member;
		}
	}

	cout << "Strongest is " << strong->getName() << endl;

	return strong;
}

void SmartTeam::attack(Team *other)
{
    if (other==nullptr)
    {
        throw invalid_argument("Null Value");
    }

    if (other==this)
    {
        throw runtime_error("Self-Attack is not possible");
    }	
	else if (_leader->isAlive() != true)
    {
        throw runtime_error("Charecter is dead, and inactive");
    }
	else if (other->_leader->isAlive() != true)
    {
        throw runtime_error("Charecter is dead, and inactive");
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
        }

        //start the attack part in the code here
        cout << "Attacker Team: " << _leader->getName() << ", Victim Team: " << other->_leader->getName() << endl;

        // find the victim of the attacker team
        Character *victim = getStrongestVictim(other);

        for (Character *member : _members)
        {
            if (!victim->isAlive()) //if the victim is dead, we pick a new one
            {
                if (other->stillAlive() == 0)
                    break;

                victim = getStrongestVictim(other);
            }
            //now we have new alive victim

            Cowboy* c = dynamic_cast<Cowboy*>(member);

            if (c != nullptr && c->isAlive())
            {
                if (c->hasboolets())
                    c->shoot(victim);

                else
                    c->reload();
            }
            else
            {
                Ninja* n = dynamic_cast<Ninja*>(member);
                if (n != nullptr && n->isAlive())
                {
                    if (n->getLocation().distance(victim->getLocation()) <= 1)
                        n->slash(victim);

                    else
                        n->move(victim);
                }
            }
        }
    }
}

void SmartTeam::print() const
{
    cout << "(SmartTeam)TeamLead: " << _leader->getName() << endl;

	for (Character *member : _members)
    {
        cout << member->print() << endl;
    }
}