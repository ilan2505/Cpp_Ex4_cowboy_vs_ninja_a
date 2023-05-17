#include "Character.hpp"

using namespace std;
using namespace ariel;


bool Character::isAlive() const{ return hitPoints > 0; }
double Character::distance(const Character* other) const {
    if(other == nullptr){ throw invalid_argument("invlaid pointer");} // Ensure the pointer isn't null
    return distance(*other);
}
double Character::distance(const Character& other) const { return location.distance(other.location); }
void Character::hit(int damage) { hitPoints -= damage; }