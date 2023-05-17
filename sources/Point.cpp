#include "Point.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace ariel;
using namespace std;


Point Point::moveTowards(const Point& src, const Point& dst, double dist){
    double dx = dst.x - src.x;
    double dy = dst.y - src.y;

    // Calculating the actual distance between source and destination
    double actualDistance = sqrt(dx*dx + dy*dy);

    // If the actual distance is less than or equal to the given distance, return destination
    if (actualDistance <= dist) { return dst; }

    // Otherwise, calculate the new point that is 'distance' units closer to the destination
    double ratio = dist / actualDistance;
    double newX = src.x + ratio * dx;
    double newY = src.y + ratio * dy;

    return Point(newX, newY);
}