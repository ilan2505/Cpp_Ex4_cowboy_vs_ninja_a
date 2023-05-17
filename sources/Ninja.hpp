#pragma once

#include "Character.hpp"

using namespace std;


namespace ariel {

    class Ninja : public Character {

        protected:
            int speed;
            Ninja(std::string name, Point location, int hitPoints, int speed) : Character(location, hitPoints, name), speed(speed) {}
        public:
            void move(Character* target);
            void slash(Character* target);
            string print() const override;

    };


    class OldNinja : public Ninja {
        public:
            OldNinja(std::string name, Point location) : Ninja(name, location, 150, 8) {} // 150 HP and 8 speed
    };

    class TrainedNinja : public Ninja {
        public:
            TrainedNinja(std::string name, Point location) : Ninja(name, location, 120, 12) {} // 120 HP and 12 speed
    };

    class YoungNinja : public Ninja {
        public:
            YoungNinja(std::string name, Point location) : Ninja(name, location, 100, 14) {} // 100 HP and 14 speed
    };


}
