#include "Ninja.hpp"
#include <iostream>


using namespace std;
using namespace ariel;


void Ninja::move(Character* target) {
    cout << "move" << endl;
}

void Ninja::slash(Character* target) {
    if (isAlive() && distance(target) < 1) {
        target->hit(40);
    }
}

string Ninja::print() const {
    // Character::print();
    cout << " and has " << speed << " speed";
    return "N";
}