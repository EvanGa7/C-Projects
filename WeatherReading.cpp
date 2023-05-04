//
//  WeatherReading.cpp
//  EighthWeatherStationProject
//
//  Created by Evan Gardner on 12/5/22.
//

#include <stdio.h>

#include "WeatherReading.h"
#include <string>
#include <iostream>
using namespace std;

WeatherReading::WeatherReading(){
    tempurature = 0.0;
    wind_speed = 0;
    direction = "";
}
WeatherReading::WeatherReading(double initial_tempurature, int initial_wind_speed, string initial_direction){
    tempurature = initial_tempurature;
    wind_speed = initial_wind_speed;
    direction = initial_direction;
}
void WeatherReading::setTempurature(double new_tempurature){
    tempurature = new_tempurature;
}
void WeatherReading::setWindSpeed(int new_wind_speed){
    wind_speed = new_wind_speed;
}
void WeatherReading::setDirection(string new_direction){
    direction = new_direction;
}
double WeatherReading::getTempurature(){
    return tempurature;
}
int WeatherReading::getWindSpeed(){
    return wind_speed;
}
string WeatherReading::getDirection(){
    return direction;
}
void WeatherReading::print(){
    cout << "Tempurature: " << getTempurature() << " degrees farenheit"<< endl;
    cout << "Wind Speed: " << getWindSpeed() << " mph" << "\tDirection: " << getDirection() << endl << endl;
}
