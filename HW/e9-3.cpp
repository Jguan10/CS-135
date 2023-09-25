/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: HW E9-3
*/

#include <iostream>

using namespace std;

class Circuit {
private:
    int first_switch;
    int second_switch;
    int lamp_state;
public:   
    int get_first_switch_state() {
        return first_switch;
    } // 0 for down, 1 for up
    int get_second_switch_state() {
        return second_switch;
    }
    int get_lamp_state() {
        return lamp_state;
    }// 0 for off, 1 for on
    void toggle_first_switch() {
        first_switch = 1 - first_switch;
        lamp_state = 1 - lamp_state;
    }
    void toggle_second_switch() {
        second_switch = 1 - second_switch;
        lamp_state = 1 - lamp_state;
    }
};

int main() {
    
    return 0;
}