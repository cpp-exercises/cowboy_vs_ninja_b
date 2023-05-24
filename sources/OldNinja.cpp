
#include "OldNinja.hpp"
// #include "Character.hpp"
// #include "Ninja.hpp"
namespace ariel
{

    OldNinja::OldNinja(string name, Point point) : Ninja(point) , Character(name,point)
    {
        this->_health = 150;
        this->_speed = 8;
        // update the type of character after its definded to be Cowboy
        this->_sort = 0;
    }

    string OldNinja::print() { return "hello"; }

    void OldNinja::slash(Character *player)
    {
        if (this->_health <= 0)
        {

            throw std::runtime_error("im dead ");
        }
        else if (this == player)
        {
            throw std::runtime_error("cannot slash my self ");
        }
        else if (!(player->isAlive()))
        {
            // im dead how i can shoot ?!!
            throw std::runtime_error("cannot slash dead player ");
        }
        else
        {
            player->hit(40);
        }
    }
};