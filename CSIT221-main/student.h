#include <string>
#include <cstdlib>

using namespace std;

struct Student
{
	string name;
	int *marks;
	int rollNumber;
	int totalMarks;
	
	Student() : name(""), rollNumber(0), totalMarks(0)
	{
		marks = new int[5];
	}
	
	int getTotalMarks()
	{
		int sum = 0, i;
		for (i = 0; i < 5; i++)
			sum += marks[i];
		return sum;
	}
};
