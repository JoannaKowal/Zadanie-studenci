#pragma once
#include "Student.h"
const int DEF_LEN = 0;
class Manager
{
public:
	Manager();
	~Manager();
	void addStudent(std::string name, std::string lastName);
	void deleteStudent(int index);
	std::string printStudents();
	void changeStudentData(int index, std::string name, std::string lastName);

private:
	Student * myStudents;
	int tableLength;
	void expandTable();
	void reduceTable(int index);
	void setStudentData(std::string name, std::string lastName);
};
