/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E6.20
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

vector<int> merge_sorted(vector<int> a, vector<int> b) {
    vector<int> merged = append(a,b);
    int holder;
    for(int i = 0; i < merged.size(); i++) {
        for(int j = 0; j < merged.size(); j++) {
            if(merged[j] > merged[i]) {
                holder = merged[i];
                merged[i] = merged[j];
                merged[j] = holder;
            }
        }
    }
    return merged;
}

int main() {
    vector<int> v1 = {1,5,7};
    vector<int> v2 = {2,7,1};
    vector<int> v3 = merge_sorted(v1,v2);
    for(int i = 0; i < v3.size(); i++) {
        cout << v3[i];
    }

    return 0;
}