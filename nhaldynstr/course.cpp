// I just prefer to have a separate file for implementations.

#include "course.hpp"

#include <iostream>
#include <cstring>
#include <cstddef>

#define DEFAULT_CAPACITY 10

Course::Course(std::string name) : m_name(name)
{
	m_size = 0;
	m_capacity = DEFAULT_CAPACITY; // You will thank yourself in the future.
	// calloc allows you to specify capacity and size instead of size only.
	// Initializes memory to zero.
	m_students = (Student*)std::calloc(m_capacity, sizeof(Student));
	if (!m_students) {
		std::cout << "Failed to allocate enough memory\n";
		m_is_valid = false; // We should not call exit from a class.
	}

	m_is_valid = true;

	std::cout << "Allocated " << m_capacity << " slots for students.\n";
}

Course::~Course(void)
{
	// We get memleaks if strings are not freed.
	for (size_t i = 0; i <= m_size-1; i++) {
		m_students[i].name.clear();
		m_students[i].name.shrink_to_fit();
	}

	std::free(m_students);
}

void Course::add_student(Student *student)
{
	if (m_size >= m_capacity) {
		std::cout << "Cannot add more student\n";
		return;
	}

	m_students[m_size].name = student->name;
	// Some pointer sorcery...
	size_t offset = offsetof(Student, id);
	std::memcpy((void*)&m_students[m_size]+offset, student+offset, sizeof(Student)-offset);
	++m_size;

	std::cout << "Student added!\n";
}

void Course::print_info(void)
{
	std::cout << "Course: " << m_name << std::endl;

	for (size_t i = 0; i < m_capacity; i++) {
		std::cout << "Student " << i + 1 << ": ";
		std::cout << ((i+1 <= m_size) ? m_students[i].name : "?") << std::endl;
	}
}

bool Course::is_valid(void)
{
	return m_is_valid;
}
