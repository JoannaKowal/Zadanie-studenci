#pragma once
#include<string>
const std::string SPACE = " ";
const std::string DEF_NAME = "student";
class Student
{
public:
	Student();
	Student(std::string name, std::string lastName);
	void setName(std::string newName);
	void setLastName(std::string newLastName);
	std::string getName();
	std::string getLastName();
	std::string toString();
private:
	std::string name;
	std::string lastName;
};
