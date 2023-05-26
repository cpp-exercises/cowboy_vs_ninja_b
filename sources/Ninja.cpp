#include "Ninja.hpp"
#include <stdexcept>
using namespace std;

namespace ariel {
    Ninja::Ninja(string name, Point location) : Character(name, location) {
    }

  

void Ninja::move(const Character* dest)
{
    if (dest != nullptr)
    {
        location = location.moveTowards(dest->location, speed);
    }
}


string Ninja::print() 
{
    return "Ninja: " + this->name + " (" + std::to_string(damageScore) + " HP)";
}



//used the help of ofri leifer
void Ninja:: slash(Character* enemy)
{
 if(!(enemy->isAlive())|| enemy==this ||!(this->isAlive()))
    {
        std::__throw_runtime_error("can't slash if he is dead/ you can't slash yourself");
    }
      if (enemy != nullptr && isAlive() && distance(enemy) < 1.0 && enemy != this)
    {
        enemy->hit(40);
    }
    else
    {
        if (enemy == nullptr)
            throw std::invalid_argument("nullptr sent to function!");
        else if (!isAlive())
            throw std::runtime_error("character is dead!");
        else if (enemy == this)
            throw std::runtime_error("No self harm!");
    }
}



Ninja::~Ninja(){}

}