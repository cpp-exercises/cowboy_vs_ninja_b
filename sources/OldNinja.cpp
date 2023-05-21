
#include "OldNinja.hpp"
// #include "Character.hpp"
// #include "Ninja.hpp"
namespace ariel
{

    OldNinja::OldNinja(string name, Point point) : Ninja(name, point)
    {
    }
    double OldNinja::distance(Character *player) const { return 0; };
    string OldNinja::getName() { return _pname; }
    Point OldNinja::getLocation() { return _location; }
    string OldNinja::print() { return "hello"; }
    void OldNinja::hit(int number_hits) {}
    void OldNinja::setName(string name) {}
    bool OldNinja::isAlive() { return true; }
};