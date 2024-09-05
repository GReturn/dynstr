#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    int yearLevel;
    string program;
};

class Course {
    string name;
    Student** students;
    int size;
    int capacity;

public:
    Course(string name) {
        this->name = name;
        size = 0;
        capacity = 10;
        students = (Student**)malloc(capacity * sizeof(Student));
        if (students == nullptr) {
            cout << "Memory allocation failed!" << endl;
            exit(1);
        }
        cout << "Allocated " << capacity << " slots for students." << endl;
    }

    void addStudent(Student* s) {
        cout << "Added\n";
        students[size++] = s;
    }

    void print() {
        cout << "Course: " << name << endl;
        for (int i = 0; i < capacity; i++) {
            cout << "Student " << i + 1 << ": ";
            if(i >= size) cout  << "?" << endl;
            else cout  << students[i]->name << endl;
        }
    }
};