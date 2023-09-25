#include <iostream>

using namespace std;

int main() {
    int intArray[] = {1000,2,3,4,100};
    int size = sizeof(intArray) / sizeof(intArray[0]);
    cout << size;
}