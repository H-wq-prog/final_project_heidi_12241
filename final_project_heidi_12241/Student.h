#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>
#include <vector>
using namespace std;

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses; // عشان نمنع التكرار

public:
    Student();
    Student(int id, string name, double gpa);

    int getId() const;
    double getGpa() const;

    void setGpa(double gpa);

    void addCourse(string course);
    void displayCourses() const;

    void display() const;
};

#endif