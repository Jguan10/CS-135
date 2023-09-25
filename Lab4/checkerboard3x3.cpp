/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: checkerboard3x3, lab 4G
*/

#include <iostream>
using namespace std;

int main() {
    int width, height;
    string ast = "*";
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    cout << "Shape:" << endl;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if ((i / 3) % 2 < 1){
                if ((j / 3) % 2 < 1){
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
            if ((i / 3) % 2 >= 1){
                if ((j / 3) % 2 >= 1){
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        } 
        cout << endl;
    }
}