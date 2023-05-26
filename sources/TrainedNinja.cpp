#include "TrainedNinja.hpp"

namespace ariel{
TrainedNinja::TrainedNinja(string _name, Point _location) : Ninja(_name, _location) {
   this->name=_name;
   this->location=_location;
   this->Alive=true;
   this->speed=12.0;
   this->damageScore=120;
}
TrainedNinja::~TrainedNinja() {}


int TrainedNinja:: getDS()
{
    return damageScore;
}




string TrainedNinja::getName()
{
    return this->name;
}

}