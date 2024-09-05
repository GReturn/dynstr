#include <iostream>
#include <cstdio>
#include "course.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Course* csit = new Course("DSA");
    char op;

    while (true) {
        cout << "Op: ";
        cin >> op;

        switch (op) {
            case 'a':
            {
                Student* s = new Student;
                cout << "Name: ";
                cin >> s->name;
                csit->addStudent(s);
                break;

            } // Add a new student
            case 'p': // Print the course details
                csit->print();
                break;

            case 'x': // Exit the loop
                return 0;

            default:
                cout << "Invalid option." << endl;
                break;
        }
    }

    return 0;
}
