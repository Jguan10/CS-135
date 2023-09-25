/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 3 Task A
*/

#include "trainer.hpp"

using namespace std;

Trainer::Trainer() {
    selected = nullptr;
}

Trainer::Trainer(std::vector <Profemon> profemons) {
    for(int i = 0; i < profemons.size(); i++) {
        if(i < 3) {
            team[i] = profemons[i];
        }
        else {
            profedex.push_back(profemons[i]);
        }
    }
    selected = &team[0];
}


bool Trainer::contains(std::string name) {
    for (int i = 0; i < 3; i++) {
        if (team[i].getName() == name) {
            return true;
        }
    }

    for (int i = 0; i < profedex.size(); i++) {
        if (profedex[i].getName() == name) {
            return true;
        }
    }

    return false;
}

bool Trainer::addProfemon(Profemon profemon) {
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

// fix remove function
bool Trainer::removeProfemon(std::string name) {
    if(!(contains(name))) {
        return false;
    }   

    for(int i = 0; i < 3; i++) {
        if(team[i].getName() == name) {
            team[i] = Profemon();
            if (selected == &team[i]) {
                selected = nullptr;
            }
            return true;
        }
    }

    for(int i = 0; i < profedex.size(); i++) {
        if(profedex[i].getName() == name) {
            for(int j = i; j < profedex.size() - 1; j++) {
                profedex[j] = profedex[j + 1];
            }
            profedex.pop_back();
            return true;
        }    
    }
    return false;
}

void Trainer::setTeamMember(int slot, std::string name) {
    int index;
    Profemon holder;
    for(int i = 0; i < profedex.size(); i++) {
        if(profedex[i].getName() == name) {
            index = i;
        }
    }
    if(team[slot].getName() == "Undefined") {
        team[slot] = profedex[index];
        for(int i = 0; i < profedex.size(); i++) {
        if(profedex[i].getName() == name) {
            for(int j = i; j < profedex.size() - 1; j++) {
                profedex[j] = profedex[j + 1];
                }
            profedex.pop_back();
            }    
        }
    }
    else {
        holder = team[slot];
        team[slot] = profedex[index];
        profedex[index] = holder;
    }
}

bool Trainer::chooseProfemon(int slot) {
    if(team[slot].getName() == "Undefined") {
        return false;
    }
    else {
        selected = &team[slot];
        return true;
    }
    return false;
}

Profemon Trainer::getCurrent() {
    return *selected;
}

void Trainer::printProfedex() {
    for(int i = 0; i < profedex.size(); i++) {
        cout << profedex[i].getName() << " [" << (profedex[i].getSpecialty() == 0 ? "ML" : profedex[i].getSpecialty() == 1 ? "SOFTWARE" : "HARDWARE") << "] | lvl " << profedex[i].getLevel()
        << " | exp " << profedex[i].getCurrentExp() << "/" << profedex[i].getExpReq() << " | hp " << profedex[i].getMaxHealth() << endl << endl;
    }
}


void Trainer::printTeam() {
    for(int i = 0; i < 3; i++) {
        if(!(team[i].getName() == "Undefined")) {
            cout << team[i].getName() << " [" << (team[i].getSpecialty() == 0 ? "ML" : team[i].getSpecialty() == 1 ? "SOFTWARE" : "HARDWARE") << "] | lvl " << team[i].getLevel()
            << " | exp " << team[i].getCurrentExp() << "/" << team[i].getExpReq() << " | hp " << team[i].getMaxHealth() << endl;
            if(team[i].getSkill1().getName() != "Undefined") {
                cout << "    " << team[i].getSkill1().getName() << " [" << team[i].getSkill1().getTotalUses() << "] : "
                << team[i].getSkill1().getDescription() << endl;
            }
            if(team[i].getSkill2().getName() != "Undefined") {
                cout << "    " << team[i].getSkill2().getName() << " [" << team[i].getSkill2().getTotalUses() << "] : "
                << team[i].getSkill2().getDescription() << endl;
            }
            if(team[i].getSkill3().getName() != "Undefined") {
                cout << "    " << team[i].getSkill3().getName() << " [" << team[i].getSkill3().getTotalUses() << "] : "
                << team[i].getSkill3().getDescription() << endl;
            }
            cout << endl;
        }
    }
}