#pragma once

#include <vector>

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;

protected:
	Command() {}

};

class JumpCommand : public Command
{
public:
	virtual void execute() { jump(); }

	void jump();
};

class LeftCommand : public Command
{
public:
	virtual void execute() { MoveLeft(); }

	void MoveLeft();
};

class RightCommand : public Command
{
public:
	virtual void execute() { MoveRight(); }

	void MoveRight();
};

class UpCommand : public Command
{
public:
	virtual void execute() { MoveUp(); }

	void MoveUp();
};

class DownCommand : public Command
{
public:
	virtual void execute() { MoveDown(); }

	void MoveDown();
};

class UndoCommand : public Command
{
public:
	virtual void execute() { Undo(); }

	void Undo();
};

class MacroCommand : public Command
{
public:
	MacroCommand();

	virtual ~MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command *);
	virtual void execute();

	std::vector<Command*> commands;
private:

};