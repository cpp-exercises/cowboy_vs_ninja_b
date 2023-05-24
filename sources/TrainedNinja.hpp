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

    class TrainedNinja : public Ninja
    {

    public:
        // ctor
        TrainedNinja(string, Point);
    };
};
#endif // TRAINEDNINJA_HPP