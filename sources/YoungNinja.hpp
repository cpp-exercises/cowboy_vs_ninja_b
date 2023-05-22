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
    private:
    public:
        // ctor
        YoungNinja(string, Point);
        double distance(Character *) const;
        string getName();
        Point getLocation();
        string print();
        void hit(int damage);
        void setName(string name);
        // bool isAlive();
        void slash(Character *player);
    };
};
#endif // YOUNGNINJA_HPP