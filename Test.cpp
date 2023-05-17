#include "doctest.h"

#include "sources/Team.hpp"
#include <iostream>
#include <cmath>

using namespace ariel;
using namespace std;

TEST_CASE("Test Character operations") {
    Point location(1, 1);
    Character* character = new Cowboy("Cowboy", location);
    CHECK(character->isAlive() == true);
    character->hit(110);
    CHECK(character->isAlive() == false);
    delete character;
}

TEST_CASE("Test Point operations") {
    Point a(0, 0);
    Point b(3, 4); // This point is 5 units from (0, 0) - Pythagoras theorem
    CHECK(a.distance(b) == doctest::Approx(5.0));
    CHECK(b.distance(a) == doctest::Approx(5.0));
}

TEST_CASE("Test Cowboy operations") {
    Point location(1, 1);
    Cowboy* cowboy = new Cowboy("Cowboy", location);
    CHECK(cowboy->hasboolets() == true);
    cowboy->shoot(new OldNinja("Enemy", Point(2, 2)));
    CHECK(cowboy->hasboolets() == true); // still have bullets after shooting
    delete cowboy;
}

TEST_CASE("Test Ninja operations") {
    Point location(1, 1);
    Ninja* ninja = new YoungNinja("Ninja", location);
    CHECK(ninja->isAlive() == true);
    ninja->hit(100);
    CHECK(ninja->isAlive() == false);
    delete ninja;
}

TEST_CASE("Test Team operations") {
    Point location(1, 1);
    Character* leader = new Cowboy("Leader", location);
    Team team(leader);
    CHECK(team.stillAlive() == 1);
    team.add(new TrainedNinja("Member", Point(2, 2)));
    CHECK(team.stillAlive() == 2);
}

TEST_CASE("Test Team2 operations") {
    Point location(1, 1);
    Character* leader = new Cowboy("Leader", location);
    Team2 team(leader);
    CHECK(team.stillAlive() == 1);
    team.add(new TrainedNinja("Member", Point(2, 2)));
    CHECK(team.stillAlive() == 2);
}

TEST_CASE("Test Team attack operations") {
    Point location1(1, 1);
    Character* leader1 = new Cowboy("Leader1", location1);
    Team team1(leader1);
    team1.add(new TrainedNinja("Member1", Point(2, 2)));

    Point location2(10, 10);
    Character* leader2 = new Cowboy("Leader2", location2);
    Team team2(leader2);
    team2.add(new TrainedNinja("Member2", Point(11, 11)));

    team1.attack(&team2);
    CHECK(team2.stillAlive() < 2); // At least one member of team2 should be hit
}

TEST_CASE("Test Cowboy reloading") {
    Point location(1, 1);
    Cowboy* cowboy = new Cowboy("Cowboy", location);
    for(int i=0; i<6; i++) {
        CHECK(cowboy->hasboolets() == true);
        cowboy->shoot(new OldNinja("Enemy", Point(2, 2)));
    }
    CHECK(cowboy->hasboolets() == false); // Should have no bullets after shooting 6 times
    cowboy->reload();
    CHECK(cowboy->hasboolets() == true); // Should have bullets after reloading
    delete cowboy;
}

TEST_CASE("Test Ninja movement") {
    Point location1(1, 1);
    Point location2(10, 10);
    Cowboy* cowboy = new Cowboy("Cowboy", location1);
    Ninja* ninja = new YoungNinja("Ninja", location2);
    double old_distance = ninja->distance(cowboy);
    ninja->move(cowboy);
    double new_distance = ninja->distance(cowboy);
    CHECK(new_distance < old_distance); // Ninja should be closer to the Cowboy after moving
    delete cowboy;
    delete ninja;
}

TEST_CASE("Test Ninja slashing") {
    Point location1(1, 1);
    Point location2(2, 2);
    Cowboy* cowboy = new Cowboy("Cowboy", location1);
    Ninja* ninja = new YoungNinja("Ninja", location2);
    CHECK(cowboy->isAlive() == true);
    ninja->slash(cowboy);
    CHECK(cowboy->isAlive() == false); // Cowboy should be dead after being slashed by Ninja
    delete cowboy;
    delete ninja;
}

TEST_CASE("Test Team leader") {
    Point location(1, 1);
    Character* leader = new Cowboy("Leader", location);
    Team team(leader);
    CHECK(team.stillAlive() == 1); // Team should be alive if leader is alive
    leader->hit(110);
    CHECK(team.stillAlive() == 0); // Team should not be alive if leader is not alive
}

TEST_CASE("Test Team2 destructor") {
    Point location(1, 1);
    Character* leader = new Cowboy("Leader", location);
    Team2* team = new Team2(leader);
    // You can't really "check" that a destructor is called in a unit test, 
    // but this will at least run the destructor code
    delete team;
}

TEST_CASE("Test Team print") {
    Point location(1, 1);
    Character* leader = new Cowboy("Leader", location);
    Team team(leader);
    // Similarly, you can't really "check" a print function, but this will at least run the code
    team.print();
}
