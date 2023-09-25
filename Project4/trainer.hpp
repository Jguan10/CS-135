/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 3 Task A
*/

#ifndef Trainer_HPP
#define Trainer_HPP

#include <iostream>
#include <string>
#include <vector>
#include "profemon.hpp"

class Trainer {
protected:
    std::vector <Profemon> profedex;
    Profemon team[3];
    Profemon *selected;
public:
    Trainer();
    Trainer(std::vector <Profemon> profemons);
    bool contains(std::string name);
    bool addProfemon(Profemon profemon);
    bool removeProfemon(std::string name);
    void setTeamMember(int slot, std::string name);
    bool chooseProfemon(int slot);
    Profemon getCurrent();
    void printProfedex();
    void printTeam();
};

#endif