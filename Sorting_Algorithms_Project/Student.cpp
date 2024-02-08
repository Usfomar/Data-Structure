//
// Created by Omar Youssif on 7/31/2023.
//
#include "Student.h"

//Default constructor
Student::Student()
{
    id = "";
    name = "";
    GPA = 0;
}

//Parameterized constructor
Student::Student(string id , string name ,double GPA)
{
    this->id = id;
    this->name = name;
    this->GPA = GPA;
}

//Getter
const string &Student::getId() const
{
    return id;
}

const string &Student::getName() const
{
    return name;
}

double Student::getGpa() const
{
    return GPA;
}

//Operator Overloading
bool Student::operator<(Student &obj)
{
    for(int i = 0 ; i < name.size();i++)
    {
        if(int(name[i]) < int(obj.name[i]))
        {
            return true;
        }
        else if (int(name[i]) == int(obj.name[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
}
bool Student::operator>(Student &obj)
{
    for(int i = 0 ; i < name.size();i++)
    {

        if(int(name[i]) > int(obj.name[i]))
        {
            return true;
        }
        else if (int(name[i]) == int(obj.name[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
}


bool Student::operator<=(Student &obj)
{
    for(int i = 0 ; i < name.size();i++)
    {
        if(int(name[i]) <= int(obj.name[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Student::operator>=(Student &obj)
{
    for(int i = 0 ; i < name.size();i++)
    {
        if(int(name[i]) >= int(obj.name[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Student::setId(const string &id)
{
    Student::id = id;
}

void Student::setName(const string &name)
{
    Student::name = name;
}

void Student::setGpa(double gpa)
{
    GPA = gpa;
}

