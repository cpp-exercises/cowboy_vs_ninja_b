#pragma once
#include <string>
#include "Point.hpp"
using namespace std;
namespace ariel{
    
class Character {
protected:
    string name;
    bool Alive;
    int damageScore;
    bool isACaptain;
    bool isPlaying;

public:
    Point location;
    Character (string _name,Point _location );
      Character(const Character&) = delete;
        Character& operator=(const Character&) = delete;
        Character(Character&&) = delete;
        Character& operator=(Character&&) = delete;
     bool isAlive();
    bool getCap();
    void setCap();
     bool getPlaying();
    void setPlaying();
    virtual double distance (Character* other);
    virtual void hit(int amountOfDamage);
    virtual string getName();
    virtual Point getLocation();
    virtual string print()=0;
    void setName(string name);
    void setLocation(Point location);
    virtual int getDS();
    virtual~Character();

};
}


