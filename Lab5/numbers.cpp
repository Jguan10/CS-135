/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: numbers, lab 5A
*/

#include <iostream>

using namespace std;

bool isDivisibleBy(int n, int d) {
    if (d == 0) {
        return false;
    }
    else if (n % d == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    for(int i = n - 1; i > 1; i--) {
        if(isDivisibleBy(n, i)) {
            return false;
        }
    }
    return true;
}

int nextPrime(int n) {
    for(int i = n + 1; i > n; i++) {
        if(isPrime(i)) {
            return i;
        }
    }
    return 0;
}

int countPrimes(int a, int b) {
    int counter = 0;
    while(a <= b) {
        if(isPrime(a))
            counter++;
        a = nextPrime(a);
    }
    return counter;
}

bool isTwinPrime(int n) {
    if(isPrime(n - 2) && isPrime(n)) {
        return true;
    }
    else if(isPrime(n + 2) && isPrime(n)) {
        return true;
    }
    return false;
}

int nextTwinPrime(int n) {
    while(true) {
        n = nextPrime(n);
        if(isTwinPrime(n)) {
            return n;
        }
    }
    return 0;
}

int largestTwinPrime(int a, int b){
    for (int i = b; i >= a; i--){
        if (isTwinPrime(i)){
            return i;//
        }
    }
    return -1;
}

int main() {   
    cout << isPrime(2);
    cout << "hi";
}