#pragma once
#include <string>
#include <vector>

struct MenuItem
{
	std::string name;
	float price;
};

class Menu
{
public:
	void AddMenuItem(MenuItem item);//declaration
	void ShowMenu();
	bool EraseItem(std::string itemToErase);

private:
	std::vector<MenuItem> items;
};

