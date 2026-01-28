#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::SerializeCSV(char delimiter, std::ofstream& outFile)
{
	//assume the file is already open
	//the class is not responsible for opening, closing
	//its only responsibility is outputting the data
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}
