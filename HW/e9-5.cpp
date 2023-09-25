/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E9-5
*/

#include <iostream>

using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double input_w, double input_h) {
        width = input_w;
        height = input_h;
    }
    double get_perimeter() {
        return 2 * width + 2 * height;
    }
    double get_area() {
        return width * height;
    }
    void resize(double factor) {
        width = factor * width;
        height = factor * height;
    }
};

int main() {

    return 0;   
}