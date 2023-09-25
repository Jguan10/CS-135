/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: pairwise.cpp
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) {
    vector<int> sum;
    int larger = max(v1.size(), v2.size());
    int smaller = min(v1.size(), v2.size());
    for(int i = 0; i < larger - smaller; i++) {
        if(v1.size() > v2.size()) {
            v2.push_back(0);
        }
        else {
            v1.push_back(0);
        }
    }
    for (int i = 0; i < larger; i++) {
        sum.push_back(v1[i] + v2[i]);
    }

    return sum;
}

int main() {
    vector<int> v1{10, 20, 30};
    vector<int> v2{1,2};    
    vector<int> v3 = sumPairWise(v1,v2);
    for(int i = 0; i < v1.size(); i++) {
        cout << v3[i] << endl;
    }
    return 0;
}