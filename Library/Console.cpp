#include <iostream>
#include <string>
#include <vector>
#include "Console.h"
#include "Library.h"
#include "Book.h"

Console::Console(Library& MyLibrary_) 
	: MyLibrary(MyLibrary_) 
{}

void Console::ConsoleCallMenu()
{
	int operation;
	do {
		operation = 0;
		std::cout << std::endl << "Enter 1 to add author, 2 to add book," << std::endl;
		std::cout << "3 to remove author, 4 to remove book," << std::endl;
		std::cout << "5 to show libary contents, 6 to rename library" << std::endl;
		std::cout << "7 for search, or enter anything else for exit." << std::endl;
		std::cout << "operation: ";
		std::cin >> operation;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;

		switch (operation) {
		case 1: ConsoleAddAuthor(); break;
		case 2: ConsoleAddBook(); break;
		case 3: ConsoleRemoveAuthor(); break;
		case 4: ConsoleRemoveBook(); break;
		case 5: ConsoleGetContents(); break;
		case 6: ConsoleRename(); break;
		case 7: ConsoleFindBooks();
		}

	} while (operation);
}

void Console::ConsoleRename()
{
	std::string new_declaration;
	std::cout << "Enter new library title: ";
	std::getline(std::cin, new_declaration);
	MyLibrary.Rename(new_declaration);
}

void Console::ConsoleGetContents()
{
	std::cout << "Library " << MyLibrary.GetDeclaration() << ":" << std::endl;
	std::vector<Book> contents = MyLibrary.GetContents();
	std::vector<Book>::iterator it;
	for (it = contents.begin(); it != contents.end(); it++) {
		std::cout << it->GetTitle() << " - ";
		std::cout << it->GetAuthor() << " - ";
		std::cout << it->GetYear() << std::endl;
	}
}

void Console::ConsoleFindBooks()
{
	std::vector<Book> results;
	std::vector<Book>::iterator it;
	int parameter;
	std::string querie;
	std::cout << "Input search parameter" << std::endl;
	std::cout << "1 for title, 2 for author name or 3 for year" << std::endl;
	std::cout << "Parameter: ";
	std::cin >> parameter;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (parameter) {
	case 1: 
		std::cout << "Input title: ";
		std::getline(std::cin, querie); 
		results = MyLibrary.FindBooksTitle(querie);
		break;
	case 2:
		std::cout << "Input author name: ";
		std::getline(std::cin, querie);
		results = MyLibrary.FindBooksAuthor(querie);
		break;
	case 3: 
		std::cout << "Input year: ";
		std::cin >> parameter;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		results = MyLibrary.FindBooksYear(parameter);
	}
	if (!results.empty()) {
		std::cout << "Search result:" << std::endl;
		for (it = results.begin(); it != results.end(); it++) {
			std::cout << it->GetTitle() << " - ";
			std::cout << it->GetAuthor() << " - ";
			std::cout << it->GetYear() << std::endl;
		}
	}
	else
		std::cout << "Found nothing :(" << std::endl;
}

void Console::ConsoleAddAuthor()
{
	std::string name;
	std::cout << "Enter name: ";
	std::getline(std::cin, name);
	if (!MyLibrary.AddAuthor(name)) 
		std::cout << "This author already exists" << std::endl;
}

void Console::ConsoleRemoveAuthor()
{
	std::string name;
	std::cout << "Enter name: ";
	std::getline(std::cin, name);
	if (!MyLibrary.RemoveAuthor(name)) 
		std::cout << "This author does not exist" << std::endl;
}

void Console::ConsoleAddBook()
{
	std::string title, author;
	int year;
	std::cout << "Enter title: ";
	std::getline(std::cin, title);
	std::cout << "Enter author name: ";
	std::getline(std::cin, author);
	std::cout << "Enter publishing date: ";
	std::cin >> year;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (!MyLibrary.AddBook(title, author, year))
		std::cout << "Book with the same title already exists" << std::endl;
}

void Console::ConsoleRemoveBook()
{
	std::string title, author;
	std::cout << "Enter title: ";
	std::getline(std::cin, title);
	std::cout << "Enter author name: ";
	std::getline(std::cin, author);
	if (!MyLibrary.RemoveBook(title, author)) 
		std::cout << "This book does not exist" << std::endl;
}
