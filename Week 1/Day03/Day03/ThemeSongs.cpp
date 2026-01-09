#include "ThemeSongs.h"
#include "../../../Shared/Console/Console.h"

void ThemeSongs::batTheme(int numberOfNas)
{
	int count = 0;
	while (count < numberOfNas)
	{
		Console::Write("na ", ConsoleColor::Yellow);
		count++;
	}
	Console::WriteLine("Batman!", ConsoleColor::Cyan);
}