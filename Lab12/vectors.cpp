/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: vectors.cpp
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector(int n) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
        v.push_back(i);
    }
    return v;
}

int main() {

    return 0;
}