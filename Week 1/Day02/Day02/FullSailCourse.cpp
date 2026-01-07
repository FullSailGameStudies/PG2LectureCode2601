#include "FullSailCourse.h"
#include <Console.h>

void FullSailCourse::AddGrades(std::vector<float>& grades) const//definition
{
	for (int i = 0; i < 10; i++)
	{
		grades.push_back(rand() % 10001 / 100.F);
	}
}

void FullSailCourse::PrintGrades(const std::vector<float>& grades) const
{
    //name = "PG2 2601";
    Console::WriteLine("\n\nPG2 2601", ConsoleColor::Cyan);
    for (auto& grade : grades)
    {
        std::cout << grade << "\n";
    }
    std::cout << "\n\n";
}
