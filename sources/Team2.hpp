#pragma once
#include "Team.hpp"

namespace ariel {
    class Team2 : public Team {

    public:
        Team2(Character* first);
        void add(Character* other)override;
        void print();
        int stillAlive() const override;
    };
}
