

#include "TrainedNinja.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
using std::string;
namespace ariel
{
    TrainedNinja::TrainedNinja(string name, Point point) : Ninja(name, point) {}
    double TrainedNinja::distance(Character *) const { return 0; };
    string TrainedNinja::getName() { return _name; }
    Point TrainedNinja::getLocation() { return Point(); }
    string TrainedNinja::print() { return "ss"; }
    void TrainedNinja::hit(int num_hit) {}
    void TrainedNinja::setName(string name) {}
    bool TrainedNinja::isAlive() { return true; }
};