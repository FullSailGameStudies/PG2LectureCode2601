// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"



/*
	╔══════════╗
	║ File I/O ║
	╚══════════╝

	3 things are required for File I/O:
	1) Open the file
	2) read/write to the file
	3) close the file



*/
int main()
{
	std::cout << "Hello PG2!\n";

	/*

		╔════════════════╗
		║ write csv data ║
		╚════════════════╝

		[  Open the file  ]
		[  Write to the file  ]
		[  Close the file  ]

		you need the path to the file
			use full path ( drive + directories + filename )
			or use relative path ( directories + filename )
			or current directory ( filename )

		Make sure to separate the data in the file with a delimiter.
		The delimiter is important because it is used
			to separate the data when reading the file back in.


		Lecture code: set a filePath variable, open an output file, write some csv data to it
	*/

	std::string name = "2601.csv";
	std::string path = "";//windows uses \ as a directory separator
	std::string finalPath = path + name;
	char delimiter = '$';
	//1) open the file
	//  - check if the file is open
	//      if not, give the user an error message
	std::ofstream outFile(finalPath);
	if (outFile.is_open())
	{
		//2) write to the file in CSV format
		//  use the '<<' (insertion operator)
		outFile << "Batman is the best" << delimiter << 5;
		outFile << delimiter << true << delimiter;
		outFile << 12.7 << delimiter << "Aquaman smells";
	}
	else
		std::cout << finalPath << " could not be opened.\n";

	//3) CLOSE the file
	//      - good programmging practice: close the file ASAP
	outFile.close();

	/*

		╔═══════════════╗
		║ read csv data ║
		╚═══════════════╝

		[  Open the file  ]
		[  read the file  ]
		[  Close the file  ]

		Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
	*/

	//1) open the file
	std::ifstream inFile(finalPath);
	if (inFile.is_open())
	{
		std::string line;
		//2) read the file
		//getline reads the stream until it reaches a '\n' OR the end of the stream
		std::getline(inFile, line);
		std::cout << line << "\n";

		std::stringstream lineStream(line);

		//parse the string to get the data
		std::string data;
		//getline reads the stream until it reaches a '$' OR the end of the stream
		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";

		//try-catch
		// put the code the might throw an exception in a try block
		try
		{
			std::getline(lineStream, data, delimiter);
			int iData = std::stoi(data);
			std::cout << iData << "\n";
		}
		//catch the possible exception
		catch (const std::exception& ex)
		{
			//handle the exception
			std::cout << "Error processing " << data << "\n";
		}


		std::getline(lineStream, data, delimiter);
		bool bData = data == "1";
		std::cout << bData << "\n";

		std::getline(lineStream, data, delimiter);
		double dData = std::stod(data);
		std::cout << dData << "\n";

		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";
	}
	else
		std::cout << finalPath << " could not be opened.\n";

	//3) CLOSE the file
	//      - good programmging practice: close the file ASAP
	inFile.close();

	/*

		╔═════════════════════╗
		║ parsing csv strings ║
		╚═════════════════════╝

		use getline on a string stream instead of a file stream

		Lecture code:
			using the line read in above, use a stringstream to split the line using getline.
			store the separate items in a vector
			parse each item in the vector to an appropriate variable.


	*/





	/*

		CHALLENGE:

		Parse the multi csv string (below) to get the data.
		NOTE: the data is a collection of object data.
		There are multiple delimiters.
		Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
		Then, separate the object csv data on objectSeparator to get the details of the object.

		EX: hero#hero#hero   each hero is separated by a #
			name^secret^age  the details of each hero is separated by a ^

	*/
	std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
	//1) read each hero
	//2) read the hero's data
	//3) print the data
	char collectionSeparator = '#';
	char objectSeparator = '^';

	std::stringstream multiStream(multi);
	while (not multiStream.eof())
	{
		std::string hero;
		std::getline(multiStream, hero, collectionSeparator);

		std::stringstream heroStream(hero);
		std::string name, secret, ageStr;
		int age;
		std::getline(heroStream, name, objectSeparator);
		std::getline(heroStream, secret, objectSeparator);
		std::getline(heroStream, ageStr, objectSeparator);
		try
		{
			age = std::stoi(ageStr);
		}
		catch (const std::exception&)
		{
			std::cout << "error processing age\n";
		}
		std::cout << "Hello citizen! I am " << name << "!!";
		std::cout << "(aka " << secret << "). And I am " << age;
		std::cout << " years old.\n";
	}
}
