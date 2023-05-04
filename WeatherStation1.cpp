//
//  WeatherStation.cpp
//  FirstProjectWeatherStation
//
//  Created by Evan Gardner on 9/9/22.
//
//  This project is a Weather Station that prints out the name of the station, current temperature, wind speed, and the direction of the wind.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //This is the declaration of the four variables that will be used for the weather station
    string weather_station("Programmer's");
    double tempurature(77);
    int wind_speed(8);
    string direction("West");
    
    //This is the portion of code that prints the weather stations information for the user
    cout << "\tThe " << weather_station << " Weather Station" << endl;
    cout << "Tempurature: " << tempurature << " degrees farenheit"<< endl;
    cout << "Wind Speed: " << wind_speed << " mph" << "\tDirection: " << direction << endl;
    return 0;
}//end of main function
