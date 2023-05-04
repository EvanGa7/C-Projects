//
//  WeatherReading.h
//  EighthWeatherStationProject
//
//  Created by Evan Gardner on 12/5/22.
//

#ifndef WeatherReading_h
#define WeatherReading_h

#pragma once
#include <string>
#include <iostream>
using namespace std;

class WeatherReading {
private:
    double tempurature;
    int wind_speed;
    string direction;
public:
    WeatherReading();
    WeatherReading(double initial_tempurature, int initial_wind_speed, string initial_direction);
    void setTempurature(double new_tempurature);
    void setWindSpeed(int new_wind_speed);
    void setDirection(string new_direction);
    double getTempurature();
    int getWindSpeed();
    string getDirection();
    void print();
};

#endif /* WeatherReading_h */
