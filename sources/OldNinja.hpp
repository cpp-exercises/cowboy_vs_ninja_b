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

    class OldNinja : public Ninja
    {

    public:
        // ctor
        OldNinja(string, Point);
    };

};
#endif