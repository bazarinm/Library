#include <string>
#include <vector>
#include "Library.h"
#include "Author.h"
#include "Book.h"

Library::Library()
	: declaration("My library")
{}
Library::Library(std::string declaration_)
	: declaration(declaration_)
{}

void Library::Rename(std::string new_declaration)
{
	declaration = new_declaration;
}

std::string Library::GetDeclaration()
{
	return declaration;
}

std::vector<Book> Library::GetContents()
{
	std::vector<Book> contents;
	std::vector<Book> new_contents;
	std::vector<Author>::iterator it;
	for (it = writers.begin(); it != writers.end(); it++) {
		new_contents = it->ListCompositions();
		contents.reserve(contents.size() + new_contents.size());
		contents.insert(contents.end(), new_contents.begin(), new_contents.end());
	}
	return contents;
}

std::vector<Book> Library::FindBooksTitle(std::string title)
{
	std::vector<Book> found;
	std::vector<Book> new_found;
	std::vector<Author>::iterator it;
	for (it = writers.begin(); it != writers.end(); it++) {
		new_found = it->FindCompositions(title);
		found.reserve(found.size() + new_found.size());
		found.insert(found.end(), new_found.begin(), new_found.end());
	}
	return found;
}

std::vector<Book> Library::FindBooksAuthor(std::string name)
{
	std::vector<Book> found;
	std::vector<Author>::iterator it;
	for (it = writers.begin(); it != writers.end(); it++) 
		if (it->GetName() == name)
			found =  it->ListCompositions();
	return found;
}

std::vector<Book> Library::FindBooksYear(int year)
{
	std::vector<Book> found;
	std::vector<Book> new_found;
	std::vector<Author>::iterator it;
	for (it = writers.begin(); it != writers.end(); it++) {
		new_found = it->FindCompositions(year);
		found.reserve(found.size() + new_found.size());
		found.insert(found.end(), new_found.begin(), new_found.end());
	}
	return found;
}

bool Library::AddAuthor(std::string name)
{
	std::vector<Author>::iterator it;
	for (it = writers.begin(); it != writers.end(); it++)
		if (it->GetName() == name)
			break;
	if (it == writers.end()) {
		Author new_author(name);
		writers.push_back(new_author);
		return 1;
	}
	else
		return 0;
}

bool Library::RemoveAuthor(std::string name)
{
	std::vector<Author>::iterator it;
	for (it = writers.begin(); it != writers.end(); it++)
		if (it->GetName() == name)
			break;
	if (it != writers.end()) {
		writers.erase(it);
		return 1;
	}
	else
		return 0;
}

bool Library::AddBook(std::string title, std::string author, int year)
{
	std::vector<Author>::iterator it;
	for (it = writers.begin(); it != writers.end(); it++)
		if (it->GetName() == author)
			break;
	if (it != writers.end())
		return it->AddComposition(title, year);
	else {
		Author new_author(author);
		writers.push_back(new_author);
		return writers.back().AddComposition(title, year);
	}
}

bool Library::RemoveBook(std::string title, std::string author)
{
	std::vector<Author>::iterator it;
	for (it = writers.begin(); it != writers.end(); it++)
		if (it->GetName() == author)
			break;
	if (it != writers.end()) {
		return it->RemoveComposition(title);
	}
	else
		return 0;
}
