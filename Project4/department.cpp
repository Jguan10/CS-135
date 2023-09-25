/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 3 Task A
*/

#include "department.hpp"

using namespace std;

MLDepartment::MLDepartment(std::vector<Profemon> profemons) {
    int index = 0;
    for(int i = 0; i < profemons.size(); i++) {
        if(profemons[i].getSpecialty() == ML || profemons[i].getSpecialty() == 0) {
            if(index < 3) {
                team[index] = profemons[i];
                index++;
            }
            else {
                profedex.push_back(profemons[i]);
            }
        }
    }
    selected = &team[0];
}

bool MLDepartment::addProfemon(Profemon profemon) {
    if(profemon.getSpecialty() == ML || profemon.getSpecialty() == 0) {
        for(int i = 0; i < 3; i++) {
            if(team[i].getName() == profemon.getName()) {
                return false;
            }
        }

        if(contains(profemon.getName())) {
            return false;
        }

        for(int i = 0; i < 3; i++) {
            if(team[i].getName() == "Undefined") {
                team[i] = profemon;
                return true;
            }
        }
        profedex.push_back(profemon);
        return true;
    }
    return false;
}

SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons) {
    int index = 0;
    for(int i = 0; i < profemons.size(); i++) {
        if(profemons[i].getSpecialty() == SOFTWARE || profemons[i].getSpecialty() == 1) {
            if(index < 3) {
                team[index] = profemons[i];
                index++;
            }
            else {
                profedex.push_back(profemons[i]);
            }
        }
    }
    selected = &team[0];
}

bool SoftwareDepartment::addProfemon(Profemon profemon) {
    if(profemon.getSpecialty() == SOFTWARE || profemon.getSpecialty() == 1) {
        for(int i = 0; i < 3; i++) {
            if(team[i].getName() == profemon.getName()) {
                return false;
            }
        }

        if(contains(profemon.getName())) {
            return false;
        }

        for(int i = 0; i < 3; i++) {
            if(team[i].getName() == "Undefined") {
                team[i] = profemon;
                return true;
            }
        }
        profedex.push_back(profemon);
        return true;
    }
    return false;
}

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons) {
    int index = 0;
    for(int i = 0; i < profemons.size(); i++) {
        if(profemons[i].getSpecialty() == HARDWARE) {
            if(index < 3) {
                team[index] = profemons[i];
                index++;
            }
            else {
                profedex.push_back(profemons[i]);
            }
        }
    }
    selected = &team[0];
}

bool HardwareDepartment::addProfemon(Profemon profemon) {
    if(profemon.getSpecialty() == HARDWARE) {
        for(int i = 0; i < 3; i++) {
            if(team[i].getName() == profemon.getName()) {
                return false;
            }
        }

        if(contains(profemon.getName())) {
            return false;
        }

        for(int i = 0; i < 3; i++) {
            if(team[i].getName() == "Undefined") {
                team[i] = profemon;
                return true;
            }
        }
        profedex.push_back(profemon);
        return true;
    }
    return false;
}