#pragma once
#include "Ninja.hpp"

namespace ariel {
    class OldNinja : public Ninja {
    public:
        OldNinja(string _name, Point _location);
        ~OldNinja();
    string getName()override;
    int getDS()override;

    };

}
