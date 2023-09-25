/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Quiz 10, lab 10
*/

#include <iostream>

using namespace std;

class Money { 
public:
    int dollars;
    int cents;
};

Money withdraw_money(Money balance, Money withdrawl) {
    Money newBalance;
    if(balance.cents < withdrawl.cents) {
        balance.dollars = balance.dollars - 1;
        balance.cents = balance.cents + 100;
    }
    newBalance.dollars = balance.dollars - withdrawl.dollars;
    newBalance.cents = balance.cents - withdrawl.cents;
    
    if(balance.dollars < withdrawl.dollars) {
        newBalance.dollars = 0;
        newBalance.cents = 0;
    }
    return newBalance;
}

int main() {
    Money starting = {100, 0};
    Money withdrawl = {2, 75};
    Money ending = withdraw_money(starting, withdrawl);
    cout << ending.dollars << " " << ending.cents << endl;
}