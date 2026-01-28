#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

Car::Car(const std::string& fieldData, char delim)
{
	//deserialize (parse) the fields out of the string
	DeserializeCSV(fieldData, delim);
}

void Car::DeserializeCSV(const std::string& fieldData, char delim)
{
	//parse the string
	std::stringstream fieldStream(fieldData);
	std::string data;
	std::getline(fieldStream, data, delim);
	mModelYear = std::stoi(data);
	std::getline(fieldStream, mMake, delim);
	std::getline(fieldStream, mModel, delim);
}

void Car::SerializeCSV(char delimiter, std::ofstream& outFile)
{
	//assume the file is already open
	//the class is not responsible for opening, closing
	//its only responsibility is outputting the data
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}
