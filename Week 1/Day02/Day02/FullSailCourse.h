#pragma once
#include <string>
#include <vector>
class FullSailCourse
{
public:
	void AddGrades(std::vector<float>& grades) const;//declaration

	//const methods do NOT change the object
	void PrintGrades(const std::vector<float>& grades) const;

	void SetName(const std::string& nm)
	{
		name = nm;
	}
	const std::string& GetName() const
	{
		return name;
	}
private:
	std::string name;
};

