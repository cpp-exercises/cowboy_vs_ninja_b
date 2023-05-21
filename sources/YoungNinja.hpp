/**
 *
 *@author Sari Safe
 *@since 15.05.23
 */

#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"

using std::string;
namespace ariel
{

    class YoungNinja : public Ninja, public Character
    {
    public:
        // ctor
        YoungNinja(string, Point);
        double distance(Character *) const;
        string getName();
        Point getLocation();
        string print();
        void hit(int);
        void setName(string name);
        bool isAlive();
    };
};
#endif // YOUNGNINJA_HPP