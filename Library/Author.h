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
	void AddComposition(Book& book);
	bool RemoveComposition(std::string title);
private:
	std::string name;
	std::vector<Book> compositions;
};

#endif