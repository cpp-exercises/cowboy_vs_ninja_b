#pragma once
#include "Character.hpp"


namespace ariel{
class Cowboy : public Character{
private: 
    int bullets;
public: 
    Cowboy(string name ,Point location);
    ~Cowboy() override;
    void shoot ( Character* enemy);
    bool hasboolets();
    void reload();
    double distance (Character* other)override;
    string getName()override;
    Point getLocation() override;
    string print() override;
    int getDS() override;
};
}