#include "Library.h"
#include "Console.h"

void main()
{
	Library my_library;
	Console my_console(my_library);
	
	my_library.Rename("Biblioteka im. Lenina");
	my_library.AddBook("Voina i Mir T1", "L.N. Tolstoy", 1876);
	my_library.AddBook("Voina i Mir T2", "L.N. Tolstoy", 1878);
	my_library.AddBook("Prestuplenie i Nakazanie", "F.M. Dostoevsky", 1876);
	my_console.ConsoleGetContents();

	my_console.ConsoleCallMenu();
}
