// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

    Car myCar(1967, "Ford", "Shelby Mustang GT500");
    std::string fileName = "garage.csv";
    char delim = '$';
    std::ofstream out(fileName);
    if (out.is_open())
    {
        myCar.SerializeCSV(delim, out);
    }
    else {
        std::cout << fileName << " could not be opened.\n";
    }
    out.close();

    //serialize the vector to a file
    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

    fileName = "gsGarage.csv";
    
    out.open(fileName);
    if (out.is_open())
    {
        int notFirst = 0;
        for (auto& car : garage)
        {
            if(notFirst++)
                out << "\n";
            car.SerializeCSV(delim, out);
        }
    }
    else {
        std::cout << fileName << " could not be opened.\n";
    }
    out.close();

    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */



    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */
}