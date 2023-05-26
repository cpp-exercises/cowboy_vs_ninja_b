#include "YoungNinja.hpp"

namespace ariel{
YoungNinja::YoungNinja(string _name, Point _location) : Ninja(_name, _location) {
   this->name=_name;
   this->location=_location;
   this->Alive=true;
   this->speed=14.0;
   this->damageScore=100;
}


YoungNinja::~YoungNinja() {}






string YoungNinja::getName()
{
    return this->name;
}



}