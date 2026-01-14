// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip> //adds formatting options to cout

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

const int NOT_FOUND = -1;
int LinearSearch(const std::vector<int>& vectorToSearch, int numberToFind)
{
    for (int i = 0; i < vectorToSearch.size(); i++)
    {
        if (numberToFind == vectorToSearch[i])
        {
            return i;
        }
    }
    return NOT_FOUND;
}

void PrintGrades(const std::map<std::string, double>& course)
{
    Console::WriteLine("\nPG2 2601", ConsoleColor::Cyan);
    for (auto& [student,grade] : course)
    {
        Console::SetForegroundColor(
            //ternary operator (shorthand for if-else)
            (grade<59.5) ? ConsoleColor::Red :
            (grade<69.5) ? ConsoleColor::Yellow :
            (grade<79.5) ? ConsoleColor::Magenta :
            (grade<89.5) ? ConsoleColor::Cyan :
            ConsoleColor::Green
        );
        std::cout << std::setw(8) << std::right << grade;
        Console::Reset();
        std::cout << " " << student << "\n";
    }
    std::cout << "\n\n";
}

int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 6;
    int foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex == NOT_FOUND)
    {
        std::cout << searchNumber << " was not found\n";
    }
    else
        std::cout << searchNumber << " was found at index " << foundIndex << "\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<std::string, float> menu;
    //2 ways to get data into a map
    //1) easy way  map[key] = value;
    menu["Gyros"] = 11.99f;
    menu["meat lovers pizza"] = 12.58f;
    menu["bean burrito"] = 5.99f;
    menu["bean burrito"] = 6.99f;//overwrites existing value

    //2) not-easy way map.insert(keyValuePair);
    std::pair<std::string, float> pair =
        std::make_pair("bacon cheez burger", 7.99f);
    menu.insert(pair);
    pair.second = 9.99f;
    auto wasInserted = menu.insert(pair);//does NOT overwrite existing values
    if (wasInserted.second)
        std::cout << "Item was inserted\n";
    else
    {
        std::cout << "that item is already on the menu. Do you want to change the price?\n";
    }

    float price = menu["dino nuggies"];//side-effect: adds the key-value pair
    std::cout << "\n\nDino Nuggies costs " << price << "\n";

    //looping
    std::cout << "\n\nPG2 Cafe\n";
    for (auto iter = menu.begin(); iter != menu.end(); iter++)
    {
        //iterator points to the key-value pair
        //pair objects have 2 parts: first (key) and second (value)
        //setw(#) - prints in the # of spaces
        //right - prints right-aligned
        std::cout << std::setw(8) << std::right << iter->second;
        std::cout << " " << iter->first << "\n";
    }
    std::cout << "\n\n";

    std::cout << "\n\nPG2 Cafe\n";
    for (auto& menuItem : menu)
    {
        std::cout << std::setw(8) << std::right << menuItem.second;
        std::cout << " " << menuItem.first << "\n";
    }
    std::cout << "\n\n";

    std::cout << "\n\nPG2 Cafe\n";
    //use structured bindings
    for (auto& [itemName,itemPrice] : menu)
    {
        std::cout << std::setw(8) << std::right << itemPrice;
        std::cout << " " << itemName << "\n";
    }
    std::cout << "\n\n";

    std::string itemToFind = "bacon cheez burger";
    auto menuItemIterator = menu.find(itemToFind);//uses binary search to find the key
    if (menuItemIterator == menu.end()) //did not find it
    {
        std::cout << itemToFind << " is not on the menu. Try Taco Bell\n";
    }
    else
    {
        float oldPrice = menuItemIterator->second;
        std::cout << itemToFind << "used to costs " << oldPrice << "\n";
        //menu[itemToFind] *= 1.1;//this forces another key lookup. NOT optimum

        // TIP:
        //   when you have the iterator, use the iterator
        menuItemIterator->second *= 1.1;
        std::cout << "Now it costs " << menuItemIterator->second << "!! Thanks Putin.\n";
    }



    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    /*
        CHALLENGE:

        Create a map that stores names (string) and numerical grades. 
        Call the variable grades.
        Add students and grades to your map.

    */

    std::vector<std::string> students = {
        "Garrett","J'Den", "La'Rue", "RJ","Anthony","Jacob","Gavin",
"Noah","Justin","Mason","Kam","Sincere",
"Sean","Leo","Christopher","Aidan","Alan","Gretchen","Heather","Jeremy","William"
    };
    srand(time(NULL));
    std::map<std::string, double> grades;
    for (auto& student : students)
    {
        grades[student] = rand() % 10001 / 100.0;
    }
    do
    {
        PrintGrades(grades);
        //write some code to find a student and curve the grade
        //print the map after curving
        std::string student = Input::GetString("Name of student to curve: ");
        if (student.empty()) break;

        auto foundStudent = grades.find(student);
        if (foundStudent == grades.end())
            std::cout << student << " is not in PG2 this month.\n";
        else
        {
            std::cout << student << " had a grade of " << foundStudent->second << ". ";
            foundStudent->second = std::min(100.0, foundStudent->second + 5);
            std::cout << "Now the grade is " << foundStudent->second << "\n";
        }

    } while (true);




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}