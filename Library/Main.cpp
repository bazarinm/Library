#include <iostream>
#include "Library.h"
#include "Console.h"

void main()
{
	Library my_library;
	Console my_console(my_library);
	int operation;
	
	my_library.Rename("Biblioteka im. Lenina");
	my_library.AddBook("Voina i Mir T1", "L.N. Tolstoy", 1876);
	my_library.AddBook("Voina i Mir T2", "L.N. Tolstoy", 1878);
	my_library.AddBook("Prestuplenie i Nakazanie", "F.M. Dostoevsky", 1876);
	my_console.ConsoleGetContents();

	do {
		operation = 0;
		std::cout << std::endl << "Enter 1 to add author, 2 to add book," << std::endl;
		std::cout << "3 to remove author, 4 to remove book," << std::endl;
		std::cout << "5 to show libary contents, 6 to rename library" << std::endl;
		std::cout << "or enter anything else for exit." << std::endl;
		std::cout << "operation: ";
		std::cin >> operation;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;

		switch (operation) {
			case 1: my_console.ConsoleAddAuthor(); break;
			case 2: my_console.ConsoleAddBook(); break;
			case 3: my_console.ConsoleRemoveAuthor(); break;
			case 4: my_console.ConsoleRemoveBook(); break;
			case 5: my_console.ConsoleGetContents(); break;
			case 6: my_console.ConsoleRename(); break;
		}

	} while (operation);
}
