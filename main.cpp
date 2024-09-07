#include <iostream>
#include "course.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Course* course = new Course("DSA");
    Student* s;
    char op;

    while (true) {
        cout << "Op: ";
        cin >> op;

        switch (op) {
            case 'a':                   // Add a new student
                s = new Student;
                cout << "Name: ";
                cin >> s->name;
                course->addStudent(s);
                break;
            case 'p':                   // Print the course details
                course->print();
                break;

            case 'x':                   // Exit the loop
                return 0;

            default:
                cout << "Invalid option." << endl;
                break;
        }
    }

    return 0;
}
