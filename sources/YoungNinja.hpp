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

    class YoungNinja : public Ninja
    {
    public:
        // ctor
        YoungNinja(string, Point);
    };
};
#endif // YOUNGNINJA_HPP