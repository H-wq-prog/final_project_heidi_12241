#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {}

Student::Student(int id, string name, double gpa) : Person(name) {
    this->id = id;
    this->gpa = gpa;
}

int Student::getId() const {
    return id;
}

double Student::getGpa() const {
    return gpa;
}

void Student::setGpa(double gpa) {
    if (gpa >= 0.0 && gpa <= 4.0)
        this->gpa = gpa;
}

void Student::addCourse(string course) {
    courses.insert(course);
}

void Student::displayCourses() const {
    if (courses.empty()) {
        cout << "No courses.\n";
        return;
    }

    for (auto c : courses) {
        cout << "- " << c << endl;
    }
}

void Student::display() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "GPA: " << gpa << endl;
}