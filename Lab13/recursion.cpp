/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: recursion.cpp
*/

#include <iostream>

using namespace std;

void printRange(int left, int right) {
    if(right >= left) {
        cout << left << " ";
        printRange(left + 1, right);
    }
}

int sumRange(int left, int right) {
    if(right >= left) {
        return left + sumRange(left + 1, right);
    }
    return 0;
}

int sumArray(int *arr, int size){
	if (size == 1) {
		return *arr;
    } 
    else if(size <= 0) {
        return 0;
    }
	return *arr + sumArray(arr + 1, size - 1);
}

bool isAlphanumeric(string s) {
    if(s == "") {
        return true;
    } 
    else if(!(isalnum(s[0]))) {
		return false;
    }
	return isAlphanumeric(s.substr(1));
}

int main() {
    int arr[] = {1,2,3};
    int size = 3;
    cout << sumArray(arr, size);
    return 0;
}