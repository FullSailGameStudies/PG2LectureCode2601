#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"
#include <Console.h>

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    //size() = # of items that have been added
    //capacity() = length of the internal array
    // size() <= capacity()
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

//copies are "expensive" (memory allocation + value copying)
void PrintMe(int num)//pass by value (COPY)
//num is a variable of the method
{
    std::cout << num;
}
//pass by REFERENCE
//  NO copy
void Print(int& num)
{
    //num points to the variable used when calling Print
    //Print has access to the variable from a different scope
    num++;
}
void Print(const std::string& msg)
{
    //msg = "Batman rules!";
    std::cout << msg;
}
void Update(int speed, int& x)
{
    x += speed;
}

//when to use pass by reference:
//  1) when the parameter is a class (generally)
//  2) the method needs to change the variable in another scope
//  3) to prevent a copy

//when to use const for pass by ref:
//  when the method does NOT change the parameter

int main()
{
    int n = 5;
    PrintMe(n);//num = n
    Print(n);
    int xPos = 5, speed = 15;
    Update(speed, xPos);
    std::cout << xPos;
    int& nRef = n;
    nRef++;
    std::cout << n << "\n";
    int n2 = 10;
    //nRef still points to n.
    //this will simply copy n2 to n
    nRef = n2;

    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
    CHALLENGE 1:

        Add a method to FullSailCourse to fill the vector of floats with grades.
        1) pass it in by reference
        2) add 10 grades to the vector
        3) after calling the method, print out the vector

        use rand(). It generates a number between 0 and 32767
        limit it to 0-100

    */
    std::vector<float> grades;
    FullSailCourse pg2;
    pg2.SetName("PG2 2601");
    std::string name = pg2.GetName();
    pg2.AddGrades(grades);


    const int UpperLimit = 10;
    for (int i = 0; i < UpperLimit; i++)
    {

    }

    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    highScores.reserve(10);//sets the internal array to the specific size
    printInfo(highScores);//size: ?  capacity: ?
    for (int i = 0; i < 11; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);


    std::string s1 = "Aquaman", s2 = "Batman";
    //_stricmp 
    // return...
    // < 0 if s1 < s2
    // == 0 if s1 == s2
    // > 0 if s1 > s2
    int result = _stricmp(s1.c_str(), s2.c_str());
    if (result < 0)
        std::cout << s1 << " is less than " << s2 << "\n";
    else if(result == 0)
        std::cout << s1 << " is equal to " << s2 << "\n";
    else if (result > 0)
        std::cout << s1 << " is greater than " << s2 << "\n";


    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500
    for (int i = 0; i < highScores.size(); i++)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
            --i;//move the index backwards
        }
    }
    //OR...
    for (int i = 0; i < highScores.size(); )
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
        else
            i++;
    }
    //OR...
    //reverse for loop
    for (int i = highScores.size() - 1; i >= 0; i--)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
    }
    //iterator
    for (auto iter = highScores.begin(); iter != highScores.end();)
    {
        if (2500 > (*iter))
        {
            iter = highScores.erase(iter);
        }
        else
            iter++;
    }


    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}