<<<<<<< HEAD
/**
 *@author Sari Safe
 *@since 15.05.23
 */
#ifndef OLDNINJA_H

#define OLDNINJA_H
#include "Ninja.hpp"

using std::string;
namespace ariel
{

    class OldNinja : public Character, public Ninja
    {
    private:
        string _name = "old ninja";

    public:
        // ctor
        OldNinja(string, Point);
        double distance(Character *) const;
        string getName();
        Point getLocation();
        string print();
        void hit(int number_hits);
        void setName(string name);
        // methods from character
        bool isAlive();
    };

};
=======
/**
 *@author Sari Safe
 *@since 15.05.23
 */
#ifndef OLDNINJA_H

#define OLDNINJA_H
#include "Ninja.hpp"

using std::string;
namespace ariel
{

    class OldNinja : public Character, public Ninja
    {
    private:
        string _pname = "old ninja";

    public:
        // ctor
        OldNinja(string, Point);
        double distance(Character *) const;
        string getName();
        Point getLocation();
        string print();
        void hit(int number_hits);
        void setName(string name);
        // methods from character
        bool isAlive();
    };

};
>>>>>>> fbc3513b760438cd93c52e48cd49c4a124c172ac
#endif