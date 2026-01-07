#include "FullSailCourse.h"

void FullSailCourse::AddGrades(std::vector<float>& grades)//definition
{
	for (int i = 0; i < 10; i++)
	{
		grades.push_back(rand() % 10001 / 100.F);
	}
}
