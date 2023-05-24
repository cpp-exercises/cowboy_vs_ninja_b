
#include "YoungNinja.hpp"
namespace ariel
{

    YoungNinja::YoungNinja(string name, Point point) : Ninja(name, point, 100, 14)
    {
        this->_sort = 0;
        this->_point = point;

    }

};