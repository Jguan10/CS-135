
/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: social3.cpp
*/

#include <iostream>

using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn) {
        username = usrn;
        displayname = dspn;
    }
    // Default Profile constructor (username="", displayname="")
    Profile() {
        username = " ";
        displayname = " ";
    }
    // Return username
    string getUsername() {
        return username;
    } // Return name in the format: "displayname (@username)"
    string getFullName() {
        return displayname + " (@" + username + ")";
    } // Change display name
    void setDisplayName(string dspn) {
        displayname = dspn;
    }
};

class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;
                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
    bool following[MAX_USERS][MAX_USERS]; 
    int findID (string usrn) {
        for(int i = 0; i < MAX_USERS; i++) {
            if(profiles[i].getUsername() == usrn) {
                return i;
            }
        }
        return -1;
    }
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network() {
    numUsers = 0;
    for(int i = 0; i < MAX_USERS; i++) {
        for(int j = 0; j < MAX_USERS; j++) {
            following[i][j] = false;
        }
    }
  }
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn){
            if (numUsers == MAX_USERS){
                return false;
            }
            for (int i = 0; i < usrn.size(); i++){
                int x = (int)usrn[i];
                if (!((x >= 48 && x <= 57) || (x >= 65 && x <= 90) || (x >= 97 && x <= 122))){
                    return false;
                }
            }
            for (int i = 0; i < MAX_USERS; i++){
                if (profiles[i].getUsername() == usrn){
                    return false;
                }
            }
            Profile p = Profile(usrn, dspn);
            profiles[numUsers] = p;
            numUsers += 1;
            return true;
        };
    bool follow(string usrn1, string usrn2){
        int num1 = -1, num2 = -1;
        for (int i = 0; i < MAX_USERS; i++){
            if (profiles[i].getUsername() == usrn1){
             num1 = i;
            }
            if (profiles[i].getUsername() == usrn2){
                num2 = i;
            }
        }
        if (num1 == -1 || num2 == -1){
            return false;
        }
        following [num1] [num2] = true;
        return true;
    }
    void printDot() {
        cout << "digraph {" << endl;
            for (int i = 0; i < numUsers; i++){
                cout << "  " << "\"@" << profiles[i].getUsername() << "\"" << endl;
            }
        cout << endl << endl;
        for (int i = 0; i < numUsers; i++){
            for (int j = 0; j < numUsers; j++){
                if (following[i][j] == true){
                    cout << "  " << "\"@" << profiles[i].getUsername() << "\" -> " << "\"@" << 
                    profiles[j].getUsername() << "\"" << endl;
                }
            }
        }
        cout << "}";
    }
};

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}