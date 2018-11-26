#pragma once
#include "Student.h"
#include <iostream>
const int DEF_LEN = 0;
const std::string PROMPT_DUPLICATE = "Taki student jest ju¿ wpisany!";
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
	void setStudentData(std::string name, std::string lastName);
	bool checkDuplicate(std::string name, std::string lastName);
};
