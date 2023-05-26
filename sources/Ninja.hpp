#pragma once    
#include "Point.hpp"
#include "Character.hpp"

namespace ariel{
class Ninja : public Character {
protected:
    double speed;

public:
    Ninja(string name, Point location);
    virtual void move(const Character * enemy);
    virtual void slash(Character * enemy); 
    ~Ninja() override;
    string print()override ;
     Ninja(const Ninja&) = delete;
        Ninja& operator=(const Ninja&) = delete;
        Ninja(Ninja&&) = delete;
        Ninja& operator=(Ninja&&) = delete;
};
}
