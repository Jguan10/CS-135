/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 3 Task A
*/

#include "profemon.hpp"

using namespace std;

Profemon::Profemon() {
    nameOfMon = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty) {
    nameOfMon = name;
    maxHp = max_health;
    specialtyOfMon = specialty;
    currentExp = 0; 
    currentLevel = 0;
    expReq = 50;
}

string Profemon::getName() {
    return nameOfMon;
}

Specialty Profemon::getSpecialty() {
    return specialtyOfMon;
}

int Profemon::getLevel() {
    return currentLevel;
}

int Profemon::getCurrentExp() {
    return currentExp;
}

int Profemon::getExpReq() {
    return expReq;
}

Skill Profemon::getSkill1() {
    return learned[0];
}

Skill Profemon::getSkill2() {
    return learned[1];
}

Skill Profemon::getSkill3() {
    return learned[2];
}

double Profemon::getMaxHealth() {
    return maxHp;
}

void Profemon::setName(string name) {
    nameOfMon = name;
}


void Profemon::levelUp(int exp) {
    exp = exp + currentExp;
    while(exp >= expReq) {
        currentLevel =  currentLevel + 1;
        exp = exp - expReq;
        if(specialtyOfMon == ML) {
            expReq = expReq + 10;
        }
        else if(specialtyOfMon == SOFTWARE) {
            expReq = expReq + 15;
        }
        else if(specialtyOfMon == HARDWARE) {
            expReq = expReq + 20;
        }
    }
    currentExp = exp;
}

bool Profemon::learnSkill(int slot, Skill skill) {
    if(slot > 2 || slot < 0) {
        return false;
    }
    if(skill.getSpecialty() != specialtyOfMon) {
        return false;
    }

    learned[slot] = skill;
    return true;
}

void Profemon::printProfemon(bool print_skills) {
    std::cout << nameOfMon << " [" << (specialtyOfMon == 0 ? "ML" : specialtyOfMon == 1 ? "SOFTWARE" : "HARDWARE") << "] | lvl " << currentLevel << " | exp " << currentExp << "/" << expReq << " | hp " << maxHp << std::endl;
    if (print_skills) {
        for (int i = 0; i < 3; i++) {
            if (learned[i].getName() != "Undefined") {
                std::cout << "    " << learned[i].getName() << " [" << learned[i].getTotalUses() << "] : " << learned[i].getDescription() << std::endl;
            }
        }
    }
}