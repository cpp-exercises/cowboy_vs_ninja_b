#include "Team2.hpp"
#include <vector>
#include <cmath>
#include <limits>
#include <iostream>

namespace ariel{

        Team2::Team2(Character *first) : Team(first){}


void Team2::add(Character* another) {
if (this->numOfWarriors==10||another== nullptr) {
throw std::runtime_error("Team is already full 12");
}
if(another->getPlaying())
{
throw std::runtime_error("is playing");
}
this->warriors.push_back(another);
another->setPlaying();
this->numOfWarriors++;
cout<<numOfWarriors<<endl;
}



void Team2:: print()
{
   std::cout << "Cowboys:" << std::endl;
    for ( auto& character : warriors) {
        if ( Cowboy* cowboy = dynamic_cast< Cowboy*>(character)) {
            std::cout << "Name: " << cowboy->getName() << ", Type: Cowboy" << std::endl;
        }
    }

    std::cout << "Ninjas:" << std::endl;
    for ( auto& character : warriors) {
        if ( Ninja* ninja = dynamic_cast< Ninja*>(character)) {
            if ( YoungNinja* youngNinja = dynamic_cast< YoungNinja*>(ninja)) {
                std::cout << "Name: " << youngNinja->getName() << ", Type: YoungNinja" << std::endl;
                        } else if ( TrainedNinja* trainedNinja = dynamic_cast< TrainedNinja*>(ninja)) {
                std::cout << "Name: " << trainedNinja->getName() << ", Type: TrainedNinja" << std::endl;
            }
            } else if ( OldNinja* oldNinja = dynamic_cast< OldNinja*>(ninja)) {
                std::cout << "Name: " << oldNinja->getName() << ", Type: OldNinja" << std::endl;

        }
    }
}

int Team2::stillAlive()const
{
int count =0;
for ( Character* warrior : this->warriors)
{
    if(warrior->isAlive())
    {
        count++;
    }
}
return count;

}



// Team2::~Team2()
// {
//    for (Character* character : warriors) {
//         delete character;
//     }
//     warriors.clear();
// }

}

