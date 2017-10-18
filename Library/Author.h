#ifndef AUTHOR_H
#define AUTHOR_H

#include <vector>
#include <string>
#include "Book.h"

class Author
{
public:
	Author(const std::string& name);

	std::string GetName();
	std::vector<Book>& ListCompositions();
	std::vector<Book> FindCompositions(const std::string& title);
	std::vector<Book> FindCompositions(int year);
	bool AddComposition(const std::string& title, int year);
	bool RemoveComposition(const std::string& title);
private:
	std::string name;
	std::vector<Book> compositions;
};

#endif