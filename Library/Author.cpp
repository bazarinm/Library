#include <vector>
#include <string>
#include "Author.h"
#include "Book.h"

Author::Author(std::string name_)
	: name(name_)
{}

std::string Author::GetName()
{
	return name;
}

std::vector<Book>& Author::ListCompositions()
{
	return compositions;
}

bool Author::AddComposition(std::string title, int year)
{
	std::vector<Book>::iterator it;
	for (it = compositions.begin(); it != compositions.end(); it++) {
		if (it->GetTitle() == title)
			break;
	}
	if (it == compositions.end()) {
		Book book(title, name, year);
		compositions.push_back(book);
		return 1;
	}
	else
		return 0;
}

bool Author::RemoveComposition(std::string title)
{
	std::vector<Book>::iterator it;
	for (it = compositions.begin(); it != compositions.end(); it++)
		if (it->GetTitle() == title)
			break;
	if (it != compositions.end()) {
		compositions.erase(it);
		return 1;
	}
	else
		return 0;
}
