#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Point.hpp"

using namespace ariel;
namespace ariel
{
    class Character
    {
        protected:
            string _name;
            Point _location;
            int _hitPoints;
            
        public:
            bool _captain;
            bool _teamate;
            //bool _active;

            Character(string name, Point location, int hitPoint);
            
            string getName() const;
            int getHitPoint() const;
            Point getLocation() const;
            void setLocation(Point& location);
            virtual ~Character() {}
            bool isAlive() const;
            double distance(Character *other) const;
            void hit(int amount);
            virtual string print() const = 0;

    };
}