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

    Car userCar("1967,Ford,Shelby Mustang GT500", ',');

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
    fileName = "garage.csv";
    std::ifstream in(fileName);
    if (in.is_open())
    {
        std::string carData;
        std::getline(in, carData);
        Car gsCar(carData, delim);
        std::cout << "\n\nG's Car: " << gsCar.vehicleInformation() << "\n";
    }
    else
    {
        std::cout << fileName << " could not be opened.\n";
    }
    in.close();

    //deserialize the gsGarage to load a vector of car objects
    //after loading, print the details of each car
    std::vector<Car> loadedCars;
    fileName = "gsGarage.csv";
    in.open(fileName);
    if (in.is_open())
    {
        //loop while there is still data in the file
        while (not in.eof())
        {
            //load the line from the file
            std::string carData;
            std::getline(in, carData);

            //create the object with the line
            Car newCar(carData, delim);

            //store the object in a vector
            loadedCars.push_back(newCar);
        }
    }
    else
    {
        std::cout << fileName << " could not be opened.\n";
    }
    in.close();

    std::cout << "\n\nLoaded Cars: " << loadedCars.size() << "\n";
    for (auto& car : loadedCars)
    {
        std::cout << car.vehicleInformation() << "\n";
    }

}