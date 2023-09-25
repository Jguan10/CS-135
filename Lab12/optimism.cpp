/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: vectors.cpp
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> goodVibes(const vector<int> v) {
    vector<int> v1;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > 0) {
            v1.push_back(v[i]);
        }
    }
    return v1;
}

int main() {
    return 0;
}