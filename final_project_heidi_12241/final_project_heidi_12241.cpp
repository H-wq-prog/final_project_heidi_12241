#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include "Student.h"

using namespace std;

map<int, Student> students;

// ---------------- FUNCTIONS ----------------

void addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";
    cin >> id;

    if (students.count(id)) {
        cout << "Student already exists!\n";
        return;
    }

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter GPA: ";
    cin >> gpa;

    if (gpa < 0 || gpa > 4) {
        cout << "Invalid GPA!\n";
        return;
    }

    students[id] = Student(id, name, gpa);
    cout << "Student added successfully.\n";
}

// ----------------

void removeStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    if (students.erase(id))
        cout << "Removed successfully.\n";
    else
        cout << "Student not found.\n";
}

// ----------------

void searchStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    if (students.count(id)) {
        students[id].display();
    }
    else {
        cout << "Student not found.\n";
    }
}

// ----------------

void displayAll() {
    if (students.empty()) {
        cout << "No students.\n";
        return;
    }

    for (auto& pair : students) {
        cout << "----------------\n";
        pair.second.display();
    }
}

// ----------------

void enrollCourse() {
    int id;
    string course;

    cout << "Enter ID: ";
    cin >> id;

    if (!students.count(id)) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter Course: ";
    cin >> course;

    students[id].addCourse(course);
    cout << "Course added.\n";
}

// ----------------

void showCourses() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    if (!students.count(id)) {
        cout << "Student not found.\n";
        return;
    }

    students[id].displayCourses();
}

// ----------------

void sortByGPA() {
    vector<Student> temp;

    for (auto& p : students)
        temp.push_back(p.second);

    sort(temp.begin(), temp.end(), [](Student a, Student b) {
        return a.getGpa() > b.getGpa();
        });

    for (auto& s : temp) {
        cout << "----------------\n";
        s.display();
    }
}

// ----------------

void menu() {
    int choice;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Enroll Course\n";
        cout << "6. Show Courses\n";
        cout << "7. Sort by GPA\n";
        cout << "8. Exit\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: removeStudent(); break;
        case 3: searchStudent(); break;
        case 4: displayAll(); break;
        case 5: enrollCourse(); break;
        case 6: showCourses(); break;
        case 7: sortByGPA(); break;
        case 8: return;
        default: cout << "Invalid choice!\n";
        }
    }
}

// ----------------

int main() {
    menu();
    return 0;
}