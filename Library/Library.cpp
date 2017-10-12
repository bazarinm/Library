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

void Library::AddBook(std::string title, std::string author, int year)
{
	Book new_book(title, author, year);
	std::vector<Author>::iterator it;
	for (it = writers.begin(); it != writers.end(); it++)
		if (it->GetName() == author)
			break;
	if (it != writers.end())
		it->AddComposition(new_book);
	else {
		Author new_author(author);
		new_author.AddComposition(new_book);
		writers.push_back(new_author);
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
