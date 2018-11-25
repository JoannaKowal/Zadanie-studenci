#include "Interface.h"

Interface::Interface()
{
	this->manager = new Manager();
	this->finished = false;
}

Interface::~Interface()
{
	delete manager;
}

void Interface::run()
{
	printCommands();
	while (!finished) {
		readCommand();
		splitCurrentCommand();
		performOperation();
	}
	std::cin.get();
}

void Interface::readCommand()
{
	std::getline(std::cin, this->currentCommand);
}

void Interface::splitCurrentCommand()
{
	std::istringstream iss(currentCommand);
	std::copy(std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		std::back_inserter(args));
}

void Interface::performOperation()
{
	if (args.size() > 0) 
	{
		int number = stoi(args.at(0));
		if (number == COMMAND_ADD_NUMBER)
		{
			processCommandAdd();
		}
		else if (number == COMMAND_PRINT_NUMBER)
		{
			processCommandPrint();
		}
		else if (number == COMMAND_CHANGE_NUMBER)
		{
			processCommandChangeStudentData();
		}
	}
	this->currentCommand = EMPTY_STRING;
	this->args.clear();
}

void Interface::printCommands()
{
	std::cout << MENU << std::endl << COMMAND_ADD_NUMBER << COMMAND_ADD << std::endl << COMMAND_DEL_NUMBER << COMMAND_DEL << std::endl << COMMAND_PRINT_NUMBER << COMMAND_PRINT<< std::endl
		<< COMMAND_CHANGE_NUMBER << COMMAND_CHANGE_DATA << std::endl << COMMAND_EXIT_NUMBER << COMMAND_EXIT << std::endl;
}
void Interface::processCommandAdd()
{
	std::string name = args.at(1).c_str();
	std::string lastName = args.at(2).c_str();
	manager->addStudent(name, lastName);
}

void Interface::processCommandPrint()
{
	std::cout<<manager->printStudents();
}

void Interface::processCommandChangeStudentData()
{
	int index = std::stoi(args.at(0).c_str());
	std::string name = args.at(1).c_str();
	std::string lastName = args.at(2).c_str();
	manager->changeStudentData(index, name, lastName);
}

