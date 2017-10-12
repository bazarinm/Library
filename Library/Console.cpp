#include <iostream>
#include <string>
#include <vector>
#include "Console.h"
#include "Library.h"
#include "Book.h"

Console::Console(Library& MyLybrary_) 
	: MyLybrary(MyLybrary_) 
{}

void Console::ConsoleRename()
{
	std::string new_declaration;
	std::cout << "Enter new library title: ";
	std::cin >> new_declaration;
	MyLybrary.Rename(new_declaration);
}

void Console::ConsoleGetContents()
{
	std::cout << "Library " << MyLybrary.GetDeclaration() << ":" << std::endl;
	std::vector<Book> contents = MyLybrary.GetContents();
	std::vector<Book>::iterator it;
	for (it = contents.begin(); it != contents.end(); it++) {
		std::cout << it->GetTitle() << " - ";
		std::cout << it->GetAuthor() << " - ";
		std::cout << it->GetYear() << std::endl;
	}
}

void Console::ConsoleAddAuthor()
{
	std::string name;
	std::cout << "Enter name: ";
	std::cin >> name;
	if (!MyLybrary.AddAuthor(name)) {
		std::cout << "This author already extists" << std::endl;
	}
}

void Console::ConsoleRemoveAuthor()
{
	std::string name;
	std::cout << "Enter name: ";
	std::cin >> name;
	if (!MyLybrary.RemoveAuthor(name)) {
		std::cout << "This author does not exist" << std::endl;
	};
}

void Console::ConsoleAddBook()
{
	std::string title, author;
	int year;
	std::cout << "Enter title: ";
	std::cin >> title;
	std::cout << "Enter author: ";
	std::cin >> author;
	std::cout << "Enter publishing date: ";
	std::cin >> year;
	MyLybrary.AddBook(title, author, year);
}

void Console::ConsoleRemoveBook()
{
	std::string title, author;
	std::cout << "Enter title: ";
	std::cin >> title;
	std::cout << "Enter author: ";
	std::cin >> author;
	if (!MyLybrary.RemoveBook(title, author)) {
		std::cout << "This book does not exist" << std::endl;
	};
}
