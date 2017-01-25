#include "stdafx.h"
#include "Command.h"

#include <iostream>

MacroCommand::MacroCommand()
{
}

MacroCommand::~MacroCommand()
{
}

void MacroCommand::execute()
{
	std::vector<Command*>::iterator cmdItr;

	for (cmdItr = commands.begin(); cmdItr != commands.end(); cmdItr++)
	{
		Command *c = (*cmdItr);
		c->execute();
	}
}

void MacroCommand::remove(Command * c)
{
	//commands.push_back(c);
	for (int i = 0; i < commands.size(); i++)
	{
		if (commands[i] == c)
		{
			commands.erase(commands.begin() + i);
		}
	}
}

void MacroCommand::add(Command * c)
{
	commands.push_back(c);
}

void JumpCommand::jump()
{
	std::cout << "Jump" << std::endl;
}

void LeftCommand::MoveLeft()
{
	std::cout << "Move Left" << std::endl;
}

void RightCommand::MoveRight()
{
	std::cout << "Move Right" << std::endl;
}
void UpCommand::MoveUp()
{
	std::cout << "Move Up" << std::endl;
}
void DownCommand::MoveDown()
{
	std::cout << "Move Down" << std::endl;
}
void UndoCommand::Undo()
{
	//std::cout << "undo" << std::endl;
	//MacroCommand* c = new MacroCommand();

	//c->commands.push_back(c);
}
