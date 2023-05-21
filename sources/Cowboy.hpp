/**
 *@author Sari Safe
 *@since 15.05.23
 */
// to dont include the header alot, once at most
#ifndef COWBOY_H

#define COWBOY_H

#include "Character.hpp"
#include <string>

namespace ariel
{

    class Cowboy : public Character
    {
    private:
        int _hitPoints;
        int number_of_boolts;
        string _name;
        Point _point;

    public:
        // ctor
        Cowboy(string, Point);
        //  methods
        void shoot(Character *player);
        bool hasboolts();
        void reload();
        double distance(Character *) const;
        string getName();
        Point getLocation();
        string print();
        void hit(int);
        void setName(string name);
        void move(Character *);
    };

};
#endif