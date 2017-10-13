#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Author.h"
#include "Book.h"

class Library
{
public:
	Library();
	Library(std::string declaration);

	void Rename(std::string new_declaration);
	std::string GetDeclaration();
	std::vector<Book> GetContents();
	bool AddAuthor(std::string name);
	bool RemoveAuthor(std::string name);
	bool AddBook(std::string title, std::string author, int year);
	bool RemoveBook(std::string title, std::string author);
private:
	std::string declaration;
	std::vector<Author> writers;
};

#endif
