/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: 3d-space.cpp, lab 9
*/

#include <iostream> 
#include <math.h>

using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

// Length of Vector
double length(Coord3D *p) {
    return sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    if(length(p1) > length(p2)) {
        return p1;
    }
    else{
        return p2;
    }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
    ppos->x = ppos->x + pvel->x *dt;
    ppos->y = ppos->y + pvel->y *dt;
    ppos->z = ppos->z + pvel->z *dt;
}

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D* p = new Coord3D;
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

void deleteCoord3D(Coord3D *p){
    delete p;
}

int main() {
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl;
}