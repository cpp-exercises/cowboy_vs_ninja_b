#include "TrainedNinja.hpp"
using namespace ariel;

TrainedNinja::TrainedNinja(string Name, Point location): Ninja(Name, location){
    this->hit_points = 120;
    this->speed = 12;
}

void TrainedNinja::move(Character* enemy){
    this->loc.moveTowards(this->loc, enemy->getLocation(), this->speed);
}