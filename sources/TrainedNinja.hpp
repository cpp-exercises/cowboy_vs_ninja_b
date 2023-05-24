#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ninja.hpp"
using namespace ariel;
namespace ariel
{
    class TrainedNinja: public Ninja
    {
        public:
            TrainedNinja(string name, Point location);
    };
}