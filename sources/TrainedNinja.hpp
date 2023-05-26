#pragma once    
#include "Ninja.hpp"

namespace ariel{
class TrainedNinja  : public Ninja {
public:
    TrainedNinja(string _name, Point _location);
    ~TrainedNinja ();
    string getName()override;
    int getDS()override;

};
}