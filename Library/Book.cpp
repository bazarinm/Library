#include <string>
#include "Book.h"

Book::Book(std::string title_, std::string author_, int year_)
	: title(title_), author(author_), year(year_)
{}

std::string Book::GetTitle()
{
	return title;
}

std::string Book::GetAuthor()
{
	return author;
}

int Book::GetYear()
{
	return year;
}

