#pragma once
#include "Manager.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
const int COMMAND_ADD_NUMBER = 1;
const std::string COMMAND_ADD = ". Add student (name, lastName)";
const int COMMAND_DEL_NUMBER = 2;
const std::string COMMAND_DEL = ". Delete student";
const int COMMAND_PRINT_NUMBER = 3;
const std::string COMMAND_PRINT = ". Print students";
const int COMMAND_CHANGE_NUMBER = 4;
const std::string COMMAND_CHANGE_DATA = ". Change student data";
const int COMMAND_EXIT_NUMBER = 5;
const std::string COMMAND_EXIT = ". Exit";
const std::string MENU = "Menu:";
const std::string EMPTY_STRING = "";
class Interface
{
public:
	Interface();
	~Interface();
	void run();
private:
	Manager* manager;
	bool finished;
	std::string currentCommand;
	std::vector<std::string> args;
	void readCommand();
	void splitCurrentCommand();
	void performOperation();
	void processCommandAdd();
	void processCommandPrint();
	void processCommandChangeStudentData();
	void printCommands();
};