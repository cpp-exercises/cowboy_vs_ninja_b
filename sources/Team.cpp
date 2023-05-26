#include <vector>
#include <cmath>
#include <limits>
#include "Team.hpp"
#include <iostream>
#include <algorithm> 
#include <cfloat>
using namespace std;

namespace ariel{


//used the help of ofri leifer and yovel zigdon

Team:: Team (Character* first){

if(first->getPlaying()|| first==nullptr|| !first->isAlive()|| first->getCap())
{
        throw std::runtime_error("Something went wrong!");
}
    else{
first->setCap();
setLeader(first);
this->leader=first;
   warriors.push_back(first);
    this->numOfWarriors=1;
    }
}




Character* Team :: getLeader()
{
return this-> leader;
}

void Team:: setLeader(Character* newLeader)
{
this->leader=newLeader;
}


void Team::add(Character *fighter)
{
    if (fighter != nullptr && warriors.size() < 10)
    {
        if (fighter->getPlaying())
        {
            throw std::runtime_error("already a team mate");
        }
        // Determine the appropriate position to insert the fighter based on their type
        auto insertPosition = warriors.end(); // Default position is at the end

        if (dynamic_cast<Cowboy *>(fighter) != nullptr)
        {
            // Find the first ninja in the team and insert before it
            for (auto it = warriors.begin(); it != warriors.end(); ++it)
            {
                if (dynamic_cast<Ninja *>(*it) != nullptr)
                {
                    insertPosition = it;
                    break;
                }
            }
        }

        // Insert the fighter at the determined position
        warriors.insert(insertPosition, fighter);
        fighter->setPlaying();
    }
    else
    {
        throw std::runtime_error("Exceeded the maximum limit of 10 fighters");
    }
}




int Team ::stillAlive() const{
int count =0;
for ( Character* character : this->warriors)
{
    
    if(character->isAlive())
    {
        count++;
    }
}
return count;
}






void Team::print() {
    std::cout << "Cowboys:" << std::endl;
    for ( auto& character : warriors) {
        if ( Cowboy* cowboy = dynamic_cast< Cowboy*>(character)) {
            std::cout << "Name: " << cowboy->getName() << ", Type: Cowboy"<< " (" + std::to_string(cowboy->getDS()) << " HP)" <<  std::endl;
        }
    }

    std::cout << "Ninjas:" << std::endl;
    for ( auto& character : warriors) {
        if ( Ninja* ninja = dynamic_cast< Ninja*>(character)) {
            if ( YoungNinja* youngNinja = dynamic_cast< YoungNinja*>(ninja)) {
                std::cout << "Name: " << youngNinja->getName() << ", Type: YoungNinja" << " (" + std::to_string(youngNinja->getDS()) << " HP)" << std::endl;
            } else if ( OldNinja* oldNinja = dynamic_cast< OldNinja*>(ninja)) {
                std::cout << "Name: " << oldNinja->getName() << ", Type: OldNinja" << " (" + std::to_string(oldNinja->getDS()) << " HP)" << std::endl;
            } else if ( TrainedNinja* trainedNinja = dynamic_cast< TrainedNinja*>(ninja)) {
                std::cout << "Name: " << trainedNinja->getName() << ", Type: TrainedNinja" << " (" + std::to_string(trainedNinja->getDS()) << " HP)" << std::endl;
            }
        }
    }
}



Team::~Team() {
    for (Character* character : warriors) {
        delete character;
    }
    warriors.clear();
}





//used the help of ofri leifer
       void Team::attack(Team *enemy){
       
        if (enemy == nullptr){
                        throw std::invalid_argument("Invalid team pointer - nullptr");
                }
                if (enemy->stillAlive() <= 0)
                {
                        throw std::runtime_error("the team is dead");
                }
                 if (this->stillAlive()<=0)
                {
                        throw std::runtime_error("the team is dead");
                }
                 if (this == enemy){
                        throw std::runtime_error("No self harm");
                }

        // Check if leader alive. if not - find new leader.
        if (!this->leader->isAlive()) {
            Character* newLeader = findAnewLeader();
            if (newLeader) {
                this->leader = newLeader;
            }
            else {
                // No living members in the attacking team, attack ends
                return;
            }
        }

       
        Character* victim = findVictim(enemy);

        if (victim) { 
            for (Character* member : this->warriors) {
                if (member->isAlive()) {
                    // Check victim still alive. if not - find new victim.
                    if (!victim->isAlive()) {
                        victim = findVictim(enemy);
                        if (victim == nullptr) return; // No victims.
                    }
                    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member)) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(victim);
                        } else {
                            // If cowboy has no bullets - reload.
                            cowboy->reload();
                        }
                    }
                }
            }
            for (Character* member : this->warriors) {
                if (member->isAlive()) {
                    if (!victim->isAlive()) {
                        victim = findVictim(enemy);
                    }
                    if (victim == nullptr) return;
                    if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
                        if (ninja->distance(victim) <= 1.0) {
                            ninja->slash(victim);
                        }
                        else {
                            // If ninja can't attack - get closer.
                            ninja->move(victim);
                        }
                    }
                }
            }
        }
    }




        Character* Team::findVictim(Team *enemy) {
        Character* victim = nullptr;
        double minDistance = DBL_MAX;

        for (Character* enemy : enemy->warriors) {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(enemy)) {
                if (cowboy->isAlive()) {
                    double distance = leader->distance(cowboy);
                    if (distance < minDistance) {
                        minDistance = distance;
                        victim = cowboy;
                    }
                }
            }
        }
        for (Character* enemy : enemy->warriors) {
            if (Ninja *ninja = dynamic_cast<Ninja *>(enemy)) {
                if (ninja->isAlive()) {
                    double distance = leader->distance(ninja);
                    if (distance < minDistance) {
                        minDistance = distance;
                        victim = ninja;
                    }
                }
            }
        }
        return victim;
    }

    // Find leader - iterates over cowboys and then ninjas.
    Character* Team::findAnewLeader() {
        // Find the nearest living character to be the new leader
        Character* newLeader = nullptr;
        double minDistance = DBL_MAX;

        for (Character* member : this->warriors) {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member)) {
                if (cowboy->isAlive()) {
                    double distance = this->getLeader()->distance(cowboy);
                    if (distance < minDistance) {
                        minDistance = distance;
                        newLeader = cowboy;
                    }
                }
            }
        }
        for (Character* member : this->warriors) {
            if (Ninja *ninja = dynamic_cast<Ninja *>(member)) {
                if (ninja->isAlive()) {
                    double distance = this->getLeader()->distance(ninja);
                    if (distance < minDistance) {
                        minDistance = distance;
                        newLeader = ninja;
                    }
                }
            }
        }
        return newLeader;
    }
};

