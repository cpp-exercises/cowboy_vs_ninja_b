#include "Ninja.hpp"
using namespace ariel;

Ninja::Ninja(string Name, Point location) : Character(Name, location){

}

string Ninja::print() const{
    // bool is_alive = this->isAlive();
    // return "N(" + name + ") Hit_points: " + to_string(hit_points) + " Location: " + loc.print() + " Is alive? " + 
    // to_string(this->isAlive()) + " ";
    return "";
}

void Ninja::slash(Character* enemy){
    if(this->isAlive() && (this->distance(enemy) > 1)){
        enemy->hit(40);
    }
    return;
}