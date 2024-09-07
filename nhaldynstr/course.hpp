#ifndef _COURSE_HPP
#define _COURSE_HPP

#include <iostream>

struct Student {
	std::string name;
	std::string program;
	int id;
	int year_level;
};

class Course {
private:
	std::string m_name;
	Student *m_students;
	size_t m_capacity;
	size_t m_size;
	bool m_is_valid;

public:
	Course(std::string name);
	virtual ~Course(void);

	void add_student(Student *student);
	void print_info(void);
	bool is_valid(void);
};

#endif
