/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 3 Task A
*/

#include "skill.hpp"

using namespace std;

Skill::Skill() {
    nameOfSkill = "Undefined";
    descriptionOfSkill = "Undefined";
    totalUses = -1;
    specialtyOfSkill = -1;
}

Skill::Skill(string name, string description, int specialty, int uses) {
    nameOfSkill = name;
    descriptionOfSkill = description;
    specialtyOfSkill = specialty;
    totalUses = uses;
}

string Skill::getName() {
    return nameOfSkill;
}

string Skill::getDescription() {
    return descriptionOfSkill;
}

int Skill::getTotalUses() {
    return totalUses;
}

int Skill::getSpecialty() {
    return specialtyOfSkill;
}

void Skill::setName(string name) {
    nameOfSkill = name;
}

void Skill::setDescription(string description) {
    descriptionOfSkill = description;
}

void Skill::setTotalUses(int uses) {
    totalUses = uses;
}

bool Skill::setSpecialty(int specialty) {
    if(specialty == 0 || specialty == 1 || specialty == 2) {
        specialtyOfSkill = specialty;
        return true;
    }
    return false;
}
