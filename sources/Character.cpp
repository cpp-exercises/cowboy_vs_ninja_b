#include "Character.hpp"
#include <iostream>
namespace ariel{
// Constructor
Character::Character(string _name, Point _location)
 : name(_name), location(_location), Alive(true), damageScore(0),isACaptain(false), isPlaying(false) {}

// Check if the character is alive
bool Character::isAlive() 
{
    if(damageScore<=0)
    {
        this->Alive=false;
    }
return this->damageScore>0;
}

bool Character::getCap()
{
    return this->isACaptain;
}

void Character :: setCap()
{
    this->isACaptain=true;
}

bool Character:: getPlaying()
{
   return this->isPlaying;
}

void Character :: setPlaying(){
this->isPlaying=true;
return ;
}

// Calculate the distance between this character and another character
double Character::distance(Character* other) {
    return location.distance(other->location);
}

// Inflict damage to the character
void Character::hit(int amountOfDamage) {
      if (amountOfDamage >= 0)
    {
        this->damageScore =damageScore-amountOfDamage;
        if (damageScore < 0)
        {
            this->damageScore = 0;
        }
    }
    else
    {
        throw std::invalid_argument("can't hit negative damage!");
    }
}

// Get the name of the character
string Character::getName() {
    return name;
}

// Get the location of the character
Point Character::getLocation() {
    return location;
}

// // Print the character's information
// string Character::print() {
// string ret = this->getName();
// return ret;
// }




// Set the name of the character
void Character::setName(string name) {
    this->name = name;
}

// Set the location of the character
void Character::setLocation(Point location) {
    this->location = location;
}

int Character :: getDS()
{
    return this->damageScore;
}


  Character::~Character() {
    
    }



}