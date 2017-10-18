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
	Library(const std::string& declaration);

	void Rename(const std::string& new_declaration);
	std::string GetDeclaration();
	std::vector<Book> GetContents();
	std::vector<Book> FindBooksTitle(const std::string& title);
	std::vector<Book> FindBooksAuthor(const std::string& name);
	std::vector<Book> FindBooksYear(int year);
	bool AddAuthor(const std::string& name);
	bool RemoveAuthor(const std::string& name);
	bool AddBook(const std::string& title, const std::string& author, int year);
	bool RemoveBook(const std::string& title, const std::string& author);
private:
	std::string declaration;
	std::vector<Author> writers;
};

#endif
