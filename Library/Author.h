#ifndef AUTHOR_H
#define AUTHOR_H

#include <vector>
#include <string>
#include "Book.h"

class Author
{
public:
	Author(std::string name);

	std::string GetName();
	std::vector<Book>& ListCompositions();
	std::vector<Book> FindCompositions(std::string title);
	std::vector<Book> FindCompositions(int year);
	bool AddComposition(std::string title, int year);
	bool RemoveComposition(std::string title);
private:
	std::string name;
	std::vector<Book> compositions;
};

#endif