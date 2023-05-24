
#include "OldNinja.hpp"
// #include "Character.hpp"
// #include "Ninja.hpp"
using std::cout;
using std::endl;
using namespace ariel;

OldNinja::OldNinja(string name, Point point) : Ninja(name, point, 150, 8)
{

    // update the type of character after its definded to be Cowboy
    this->_sort = 0;
    this->_point = point;
}
