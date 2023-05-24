#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ninja.hpp"
using namespace ariel;
namespace ariel
{
    class YoungNinja: public Ninja
    {
        public:
            YoungNinja(string name, Point location);
    };  
}