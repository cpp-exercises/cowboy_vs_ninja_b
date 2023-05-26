#pragma once    
#include "Ninja.hpp"
namespace ariel{

class YoungNinja : public Ninja {
public:
    YoungNinja(string _name, Point _location);
    ~YoungNinja();
    string getName()override;
};
}