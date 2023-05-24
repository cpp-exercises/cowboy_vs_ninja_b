#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ninja.hpp"
using namespace ariel;
namespace ariel
{
    class OldNinja: public Ninja
    {
        public:
            OldNinja(string name, Point location);
    };
}