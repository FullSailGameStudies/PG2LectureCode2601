#include "Menu.h"
#include <Console.h>

void Menu::AddMenuItem(MenuItem item)
{
	items.push_back(item);
}

void Menu::ShowMenu()
{
	Console::WriteLine("\n\nPg2 Cafe", ConsoleColor::Cyan);
	for (int i = 0; i < items.size(); i++)
	{
		MenuItem item = items[i];
		Console::WriteLine(item.name + " " + std::to_string(item.price));
	}

	Console::WriteLine("\n\nPg2 Cafe", ConsoleColor::Cyan);
	//range-based for loop
	for (auto& item : items)
	{
		Console::WriteLine(item.name + " " + std::to_string(item.price));
	}

	//iterators
	// objects that "point" inside of a collection
	// they "know" how to move through the collection
	// begin() - gives you the iterator to the first item in the vector
	std::vector<MenuItem>::iterator firstItem = items.begin();
	// end() - gives you the iterator to the item AFTER the last item???????????
	std::vector<MenuItem>::iterator lastItem = items.end() - 1;

	//iterators are NOT indexes
	//use the -> to access the members of the object it points to
	std::cout << firstItem->name << "\n";
	Console::WriteLine("\n\nPg2 Cafe", ConsoleColor::Cyan);
	for (auto item = items.begin(); item != items.end(); item++)
	{
		Console::WriteLine(item->name + " " + std::to_string(item->price));
	}


	std::cout << "\n\n";
}

bool Menu::EraseItem(std::string itemToErase)
{
	//erase(iterator)
	//begin() + index gives an iterator to the item
	//auto iter = items.begin() + 2;//iterator to the 3rd item
	//items.erase(items.begin() + 2);

	for (int i = 0; i < items.size(); i++)
	{
		MenuItem item = items[i];
		if (itemToErase == item.name)
		{
			items.erase(items.begin() + i);
			return true;
		}
	}
	return false;


	for (auto item = items.begin(); item != items.end(); item++)
	{
		if (itemToErase == item->name)
		{
			items.erase(item);
			return true;
		}
	}
	return false;
}
