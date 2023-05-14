#include "Team.hpp"
using namespace ariel;

Team::Team(Character* character) : leader(character){
}

Team::Team(Team& other) : leader(other.leader), war(other.war){

}

Team::~Team(){

}

Team::Team(Team&& other) noexcept
    : leader(other.leader), war(std::move(other.war))
{
    other.leader = nullptr;
}

Team& Team::operator=(Team&& other) noexcept
{
    if (this != &other)
    {
        delete leader;
        leader = other.leader;
        war = std::move(other.war);
        other.leader = nullptr;
    }
    return *this;
}

// Team& Team::operator=(const Team& other)
// {
//     if (this != &other)
//     {
//         delete leader;
//         for (auto& warrior : war)
//         {
//             delete warrior;
//         }
//         war.clear();
//         leader = new Character(*other.leader);
//         for (const auto& warrior : other.war)
//         {
//             war.push_back(new Character(*warrior));
//         }
//     }
//     return *this;
// }


void Team::add(Character* warrior){

}

void Team::attack(Team* enemies){

}

int Team::stillAlive(){
return 0;
}

void Team::print(){

}