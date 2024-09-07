#include "course.hpp"

#include <iostream>

int main(void)
{
	Course *course = new Course("DSA");
	Student student = {}; // No need to make this a pointer.
	bool running = true;

	if (course->is_valid() == false) {
		return 1;
	}

	while (running) {
		char op = 0;
		std::cout << "Op: ";
		std::cin >> op;

		switch (op) {
		case 'a':
			std::cout << "Name: ";
			std::cin >> student.name;
			course->add_student(&student);
			break;
		case 'p':
			course->print_info();
			break;
		case 'x':
			running = false;
			break;
		default:
			std::cout << "Invalid option\n";
			// No need to add break at the last case.
		}
		
		student = {}; // Reset.
	}

	// We free what we allocated.
	delete course;

	return 0;
}
