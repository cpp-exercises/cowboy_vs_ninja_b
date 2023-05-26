#include "OldNinja.hpp"
namespace ariel{
OldNinja::OldNinja(string _name, Point _location) : Ninja(_name, _location) {
   this->name=_name;
   this->location=_location;
   this->Alive=true;
   this->speed=8.0;
   this->damageScore=150;
}

OldNinja::~OldNinja() {}

int OldNinja:: getDS()
{
    return damageScore;
}

string OldNinja::getName()
{
    return this->name;
}

}