
#include "YoungNinja.hpp"
namespace ariel
{

    YoungNinja::YoungNinja(string name, Point point) : Ninja(name, point)
    {
    }
    double YoungNinja::distance(Character *) const { return 0; };
    string YoungNinja::getName() { return _name; }
    Point YoungNinja::getLocation() { return Point(); }
    string YoungNinja::print() { return "ss"; }
    void YoungNinja::hit(int num_hit) {}
    void YoungNinja::setName(string name) {}
    bool YoungNinja::isAlive() { return true; }
};