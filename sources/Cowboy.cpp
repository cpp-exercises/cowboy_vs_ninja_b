#include "Cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string Name, Point location) : Character(Name, location), num_of_bullets(6)
{
    this->hit_points = 110;
}

string Cowboy::print() const{
    // bool is_alive = this->isAlive();
    // return "C(" + name + ") Hit_points: " + to_string(hit_points) + " Location: " + loc.print() + " Is alive? " + 
    // to_string(this->isAlive()) + " ";
    return "";
}

void Cowboy::shoot(Character* enemy){
    if(this->isAlive() && this->hasboolets()){
        enemy->hit(10);
        this->num_of_bullets-=1;
    }
    return;
}

bool Cowboy::hasboolets(){
    return this->num_of_bullets > 0;
}

void Cowboy::reload(){
    this->num_of_bullets = 6;
}