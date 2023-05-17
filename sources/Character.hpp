#pragma once

#include "Point.hpp"
#include <string>

using namespace std;

namespace ariel {

    class Character {

        Point location;
        int hitPoints;
        std::string name;

    public:
        Character(Point location, int hitPoints, std::string name) : location(location), hitPoints(hitPoints), name(name) {}
        virtual ~Character() = default;
        bool isAlive() const;
        virtual double distance(const Character& other) const;
        virtual double distance(const Character* other) const;
        void hit(int damage) ;
        std::string getName() const { return name; }
        Point getLocation() const { return location; }
        virtual string print() const = 0;

    };
}