#include "Manager.h"

Manager::Manager()
{
	myStudents = nullptr;
	tableLength = DEF_LEN;
}

Manager::~Manager()
{
	delete[] myStudents;
}

void Manager::addStudent(std::string name, std::string lastName)
{
	if (myStudents == nullptr)
	{
		tableLength += 1;
		myStudents = new Student[tableLength];
		setStudentData(name, lastName);
	}
	else
	{
		expandTable();
		setStudentData(name, lastName);
	}
}

std::string Manager::printStudents()
{
	std::string students = "";
	for (int i = 0; i < tableLength; i++)
	{
		students += std::to_string(i + 1);
		students += ".";
		students += myStudents[i].toString();
		students += "\n";
	}
	return students;
}

void Manager::expandTable()
{
	Student* temp = new Student[tableLength + 1];
	for (int i = 0; i < this->tableLength; i++)
	{
		temp[i] = myStudents[i];
	}
	delete[] myStudents;
	myStudents = temp;
	tableLength = tableLength + 1;
}

void Manager::setStudentData(std::string name, std::string lastName)
{
	myStudents[tableLength - 1].setName(name);
	myStudents[tableLength - 1].setLastName(lastName);
}