
#include "Cowboy.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace ariel;

void Cowboy::shoot(Character* target) {
    if (isAlive() && hasboolets()) {
        target->hit(10);
        bullets--;
    }
}

string Cowboy::print() const {
    // Character::print();
    cout << " and has " << bullets << " bullets";
    return "C";
}