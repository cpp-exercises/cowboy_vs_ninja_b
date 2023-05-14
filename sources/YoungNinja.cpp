#include "YoungNinja.hpp"
using namespace ariel;

YoungNinja::YoungNinja(string Name, Point location) : Ninja(Name, location){
    this->hit_points = 100;
    this->speed = 14;
}

void YoungNinja::move(Character* enemy){
    this->loc.moveTowards(this->loc, enemy->getLocation(), this->speed);    
}