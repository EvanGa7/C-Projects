//
//  WeatherStation2.cpp
//  SecondProjectWeatherStation
//
//  Created by Evan Gardner on 9/16/22.
//
//  This project is a Weather Station that prints out the name of the station, current temperature, wind speed, and the direction of the wind. This is with the addition of being able to input the different elements of the weather station as previously namked and check whether the inputs are valid.

#include <iostream>
//string manipulation
#include <string>
//input output manipulation
#include <iomanip>
using namespace std;

int main() {
    
    //This is the declaration of the four variables that will be used for the weather station
    string weather_station;
    double tempurature;
    int wind_speed;
    string direction;

//----------------------------------------------------------------------------------------------
    
    //This is the portion of code asking for the name input for the wether station
    cout << "Please input the desired weather station name: ";
    getline( cin, weather_station);
    
//----------------------------------------------------------------------------------------------
    
    //This is the portion of code asking for the tempurature input for the wether station
    cout << "Please input the tempurature you would like to use: ";
    cin >> tempurature;
    
        //This is the portion of the code that will validate the tempurature value and make sure that it is a int value that was entered and if not will make the user input a new value
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new temperature input:  ";
    
            //Clearing the cin and then ignoring the charctaer cases that have been entered so that the new input can be stored
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> tempurature;
        }//end of while loop

//----------------------------------------------------------------------------------------------
    
    //This is the portion of code asking for the wind speed input for the wether station
    cout << "Please input the wind speed you would like to use: ";
    cin >> wind_speed;
    
        //This is the portion of the code that will validate the wind speed value and make sure that it is a int value that was entered and if not will make the user input a new value
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new wind speed:  ";
    
            //Clearing the cin and then ignoring the charctaer cases that have been entered so that the new input can be stored
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> wind_speed;
        }//end of while loop
    
//----------------------------------------------------------------------------------------------
    
    //This is the portion of code asking for the wind direction input for the wether station
    cout << "Please input the wind direction you would like to use: ";
    cin.ignore(1000,'\n');
    getline(cin, direction);
    
//----------------------------------------------------------------------------------------------
    
    //This is the portion of code that prints the weather stations information for the user
    cout << "\n\n\tThe " << weather_station << " Weather Station" << endl;
    cout << "Tempurature: " << tempurature << " degrees farenheit"<< endl;
    cout << "Wind Speed: " << wind_speed << " mph" << "\tDirection: " << direction << endl;
    
//----------------------------------------------------------------------------------------------

    return 0;
}//end of main function
