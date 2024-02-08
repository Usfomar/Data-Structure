//
// Created by Omar Youssif on 7/31/2023.
//

#ifndef TRAIL_STUDENT_H
#define TRAIL_STUDENT_H
#include<iostream>
using namespace std;

class Student {
private:
    //Attributes
    string id;
    string name;
    double GPA;

public:
    //Constructors
    Student();
    Student(string id , string name , double GPA);

    //Getters
    const string &getId() const;
    const string &getName() const;
    double getGpa() const;
    //comparison overloading
    bool operator< (Student& obj);
    bool operator> (Student& obj);
    bool operator>= (Student& obj);
    bool operator<= (Student& obj);
    //Setters
    void setId(const string &id);
    void setName(const string &name);
    void setGpa(double gpa);
};



#endif //TRAIL_STUDENT_H
