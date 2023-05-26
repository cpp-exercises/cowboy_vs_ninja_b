#include <iostream>
#include "Cowboy.hpp"

namespace ariel{
Cowboy::Cowboy(string _name, Point _location) : Character(_name, _location) {
    this->name = _name;
    this->location = _location;
    this->bullets=6;
    this->damageScore=110;
    this->Alive=true;
}



bool Cowboy::hasboolets() {
if(this->bullets==0)
{
    return false;
}
else return true;
}


void Cowboy::shoot(Character* enemy) {
    if (this->Alive!=true|| this==enemy)
    {
       std :: __throw_runtime_error(" is dead/ or you cnat shhot yourself dummy ");
    }
    if(!(enemy->isAlive()))
    {
        std::__throw_runtime_error("can't shoot he is dead");
    }
    if(this->bullets==0)
    {
    enemy->hit(0);
    return;
    }
    this->bullets-=1;
    enemy->hit(10);
}



double Cowboy::distance(Character* other){
return  this->getLocation().distance(other->getLocation());
}

Point Cowboy::getLocation()
{
    return this->location;
}



string Cowboy::getName()
{
    return this->name;
}

string Cowboy::print() 
{
    return "Cowboy: " + this->name + " (" + std::to_string(damageScore) + " HP)";
}

int Cowboy:: getDS()
{
    return damageScore;
}


void Cowboy::reload ()
{
    if(!isAlive())
    {
        std :: __throw_runtime_error(" cnet reload he is dead");
    }
 this->bullets=6;
}

 Cowboy::~Cowboy(){}

}

