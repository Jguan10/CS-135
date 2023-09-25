/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: vectors.cpp
*/

#include <iostream>
#include <vector>

using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta) {
    for(int i = 0; i < vegeta.size(); i++) {
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}

int main() {
    return 0;
}