#include "OldNinja.hpp"
using namespace ariel;

OldNinja::OldNinja(string Name, Point location): Ninja(Name, location){
    this->hit_points = 150;
    this->speed = 8;
}

void OldNinja::move(Character* enemy){
    this->loc.moveTowards(this->loc, enemy->getLocation(), this->speed);
}