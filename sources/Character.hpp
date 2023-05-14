//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_CHARACTER_HPP
#define CPP_EX4_PARTA_CHARACTER_HPP


#include <iostream>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    protected:
        // Character location
        Point &loc;
        int hit_points;
        string name;

    public:
        // Initializer constructor with the name of the Character and his location in the board
        Character(string Name, Point &location);
        // Copy constructor
        Character(Character& other);
        // Move constructor
        Character(Character&& other) noexcept;
        // Move assignment operator
        Character& operator=(Character&& other) noexcept;
        // Copy assignment operator
        Character& operator=(const Character& other);
        // Destructor to free allocated memory must be virtual because there are classes that inherit
        // from this class
        virtual ~Character() = default;
        // Checking if the charcter is still alive or not
        bool isAlive();
        // Calculating the distance between the locations of this object and other
        double distance(Character* other);
        // Getting hit from some Character and in result reduce the hit_points
        void hit(int hitting_points);
        string getName();
        Point& getLocation() const;
        virtual string print() const = 0;
    };
}

#endif // CPP_EX4_PARTA_CHARACTER_HPP
