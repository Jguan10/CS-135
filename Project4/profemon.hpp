;/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 3 Task A
*/

#ifndef Profemon_HPP 
#define Profemon_HPP

#include "skill.hpp"

enum Specialty {ML, SOFTWARE, HARDWARE};

class Profemon{
private:
    std::string nameOfMon;
    int expReq;
    int currentExp;
    int currentLevel;
    double maxHp;
    Skill learned[3]; 
    Specialty specialtyOfMon; 
public: 
    Profemon();
    Profemon(std::string name, double max_health, Specialty specialty);
    std::string getName();
    Specialty getSpecialty();
    int getCurrentExp();
    int getExpReq();
    int getLevel();
    Skill getSkill1();
    Skill getSkill2();
    Skill getSkill3();
    double getMaxHealth();
    void setName(std::string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);
    void printProfemon(bool print_skills);
};

#endif