<<<<<<< HEAD
/**
 *
 *@author Sari Safe
 *@since 15.05.23
 */

#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Ninja.hpp"


using std::string;
namespace ariel
{

    class TrainedNinja : public Ninja, public Character
    {
    private:
        bool inAlive = true;
        int health = 0;

    public:
        TrainedNinja(string, Point);
        double distance(Character *) const;
        string getName();
        Point getLocation();
        string print();
        void hit(int);
        void setName(string name);
        bool isAlive();
    };
};
=======
/**
 *
 *@author Sari Safe
 *@since 15.05.23
 */

#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Ninja.hpp"

using std::string;
namespace ariel
{

    class TrainedNinja : public Ninja, public Character
    {
    public:
        TrainedNinja(string, Point);
        double distance(Character *) const;
        string getName();
        Point getLocation();
        string print();
        void hit(int);
        void setName(string name);
        bool isAlive();
    };
};
>>>>>>> fbc3513b760438cd93c52e48cd49c4a124c172ac
#endif // TRAINEDNINJA_HPP