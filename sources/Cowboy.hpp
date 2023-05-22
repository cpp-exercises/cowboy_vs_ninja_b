<<<<<<< HEAD
/**
 *@author Sari Safe
 *@since 15.05.23
 */
// to dont include the header alot, once at most
#ifndef COWBOY_H

#define COWBOY_H

#include "Character.hpp"
#include <string>
#include <stdio.h>
#include <iostream>

using std::to_string;

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
        bool hasboolets();
        void reload();
        double distance(Character *) const;
        string getName();
        Point getLocation();
        string print();
        void hit(int);
        void setName(string new_name);
        //void move(Character *);
        //void setHealth(int afterShoot);
    };

};
=======
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
>>>>>>> fbc3513b760438cd93c52e48cd49c4a124c172ac
#endif