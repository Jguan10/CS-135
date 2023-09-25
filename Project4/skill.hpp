/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 3 Task A
*/

#ifndef Skill_HPP
#define Skill_HPP

#include <iostream>
#include <string>

class Skill {
private:
    std::string nameOfSkill;
    std::string descriptionOfSkill;
    int totalUses;
    int specialtyOfSkill; /*will be a 0,1,2*/
public:
    Skill();
    Skill(std::string name, std::string description, int specialty, int uses);
    std::string getName();
    std::string getDescription();
    int getTotalUses();
    int getSpecialty();
    void setName(std::string name);
    void setDescription(std::string description);
    void setTotalUses(int uses);
    bool setSpecialty(int specialty);

};   

#endif