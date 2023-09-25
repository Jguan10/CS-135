 /**
    @file smaller.cpp
    @author Jiaxiong Guan
    @date 2023-1-26
 */

#include <iostream>
using namespace std;

int main() {
    int num1 = 0;
    int num2 = 0;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    if(num1 > num2) {
        cout << num2;
    }
    else {
        cout << num1;
    }
    return 0;
}