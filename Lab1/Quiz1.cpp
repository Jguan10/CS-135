 /**
    @file e210.cpp
    @author Jiaxiong Guan
    @date 2023-1-26
 */

#include <iostream>
using namespace std;

int main() {
    int times = 0;
    cout << "Enter the number of times to print: ";
    cin >> times;
    for(int i = 0; i < times; i++) {
        cout << "I love C++\n";
    }
    return 0;
}
