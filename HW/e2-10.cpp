 /*
    @file e210.cpp
    @author Jiaxiong Guan
    @date 2023-1-26
    @assignment hw e2.10
 */

#include <iostream>
using namespace std;

int main() {
    float gallons = 0;
    float efficiency = 0;
    float price = 0;

    cout << "What is the number of gallons: ";
    cin >> gallons;
    cout << "What is the efficiency: ";
    cin >> efficiency;
    cout << "What is the price: ";
    cin >> price;

    float costPer100 = (100 / efficiency) * price;
    float howFar = efficiency * gallons;
    cout << "Cost per 100 miles is: " << costPer100;
    cout << "How far the car can go is: " << howFar;
}