//
//  WeatherStation8.cpp
//  EighthProjectWeatherStation
//
//  Created by Evan Gardner on 11/15/22.
//
//  This project is a weather station created to be able to print out the user inputted weather station name, current tempurature, wind speed, and the direction of the wind. As stated the program will accept inputs from the user, this will store the the amount inputs declared by the user while also ensuring that the inputs for tempurature and wind speed are both validated. The program has been optimized in a object oriented fashion to make it so all of the features are broken up into functions to improve reusability and efficency. The program's features include the prompt for the user to input a name for the program which will be stored for the duration of the run time. This is then followed by a menu with four options including Input which allows the user to input data into the program, Print Most Recent Weather Report which allows the user to print out the last weather report data they entered into the program, Print Weather History which will print the amount of entries declared by the user into the program or if that many have not be entered then it will print out that number of entries all from newest to oldest, and finally the option to exit the program.

//initialization of the program
#include <iostream>
//string manipulation
#include <string>
//input output manipulation
#include <iomanip>
//weather station class implementation
#include "WeatherStation.h"
//weather reading class implementation
#include "WeatherReading.h"
using namespace std;

int main() {
    string name;
    int size;
    
    //This block is used to prompt the user for a name of the weather station and then storing that name till it is terminated
    cout << "Please input the desired weather station name: ";
    getline(cin, name);
    
    //This block is used to prompt the user for a size of weather history and then stores the input while also declaring the size for each of the arrays
    cout << "Please input the desiered size of the weather station history: ";
    cin >> size;
    
    WeatherStation weather (name,size);
    weather.menu();
}
