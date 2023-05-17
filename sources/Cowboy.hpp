#pragma once

#include "Character.hpp"

using namespace std;

namespace ariel {

    class Cowboy : public Character {

        int bullets;

        public:
            Cowboy(string name, Point location) : Character(location, 110, name), bullets(6) {}
            void shoot(Character* target);
            bool hasboolets() const { return bullets > 0; }
            void reload() { bullets = 6; }
            string print() const override;

    };
}