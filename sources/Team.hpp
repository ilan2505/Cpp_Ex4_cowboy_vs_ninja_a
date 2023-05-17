#pragma once

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

namespace ariel {

    class Team {

        Character* leader;
        std::vector<Character> members;

    public:

        Team(Character* leader) {}
        virtual ~Team() = default;
        virtual void add(Character* member);
        virtual void attack(Team* other);
        virtual int stillAlive() const;
        virtual void print() const { cout << "Team" << endl;}

    };


        class Team2 : public Team{

        Character* leader;
        std::vector<Character> members;

    public:
        Team2(Character* leader) : Team(leader) {}
        ~Team2() override {
            cout << "Team2 destructor" << endl;
        }

    };

}

