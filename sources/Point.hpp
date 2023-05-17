#pragma once

#include <iostream>
#include <cmath>

using namespace std;

namespace ariel {

    class Point {

        double x;
        double y;

        public:
            Point(double x, double y) : x(x), y(y) {}
            double distance(const Point& other) const { return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));}
            void print() const { 
                cout << "(" << x << ", " << y << ")" << endl;
            }
            static Point moveTowards(const Point& src, const Point& dst, double dist);
            double X() { return x;}
            double Y() { return y;}
    };
}
