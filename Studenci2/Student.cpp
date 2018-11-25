#include"Student.h"

Student::Student()
{
	this->name = DEF_NAME;
}

Student::Student(std::string name, std::string lastName)
{
	this->name = name;
	this->lastName = lastName;
}

void Student::setName(std::string newName)
{
	this->name = newName;
}

void Student::setLastName(std::string newLastName)
{
	this->lastName = newLastName;
}

std::string Student::getName()
{
	return this->name;
}

std::string Student::getLastName()
{
	return this->lastName;
}

std::string Student::toString()
{
	return std::string(this->name + SPACE + this->lastName);
}
