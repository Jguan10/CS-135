/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E7.16
*/

#include <iostream>
#include <cmath>

using namespace std; 

struct Point{
    public:
        double x,y;
};

double distance(Point a, Point b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(){
    Point a,b;
    cout << "Enter x value for point a: ";
    cin >> a.x;
    cout << "Enter y value for point a: ";
    cin >> a.y;
    cout << "Enter x value for point b: ";
    cin >> b.x;
    cout << "Enter y value for point b: ";
    cin >> b.y;
    cout << distance(a,b);

    return 0;
}
