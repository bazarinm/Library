#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
	Book(std::string title, std::string author, int year);

	std::string GetTitle();
	std::string GetAuthor();
	int GetYear();
private:
	std::string title;
	std::string author;
	int year;
};

#endif
