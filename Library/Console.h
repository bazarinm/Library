#ifndef CONSOLE_H
#define CONSOLE_H

#include "Library.h"

class Console 
{
public:
	Console(Library& MyLibrary);

	void ConsoleCallMenu();
	void ConsoleRename();
	void ConsoleGetContents();
	void ConsoleFindBooks();
	void ConsoleAddAuthor();
	void ConsoleRemoveAuthor();
	void ConsoleAddBook();
	void ConsoleRemoveBook();
private:
	Library& MyLibrary;
};

#endif
