/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E6.8
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> append(vector<int> a, vector<int> b) {
    vector<int> combined;
    for(int i = 0; i < a.size(); i++) {
        combined.push_back(a[i]);
    }
    for(int i = 0; i < b.size(); i++) {
        combined.push_back(b[i]);
    }
    return combined;
}

int main() {
    return 0;
}