#ifndef CONSOLE_H
#define CONSOLE_H

#include "Library.h"

class Console 
{
public:
	Console(Library& MyLybrary);

	void ConsoleRename();
	void ConsoleGetContents();
	void ConsoleAddAuthor();
	void ConsoleRemoveAuthor();
	void ConsoleAddBook();
	void ConsoleRemoveBook();
private:
	Library& MyLybrary;
};

#endif
