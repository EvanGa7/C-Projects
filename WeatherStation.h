//
//  WeatherStation.h
//  EighthWeatherStationProject
//
//  Created by Evan Gardner on 12/5/22.
//

#ifndef WeatherStation_h
#define WeatherStation_h

#pragma once
#include <string>
#include "WeatherReading.h"
#include <iostream>
using namespace std;

class WeatherStation: public WeatherReading {
private:
    string name;
    int size;
    WeatherReading* history;
    int counter;
    bool running;
    int option_choice;
    bool check_option_1;
public:
    WeatherStation(string name, int size);
    ~WeatherStation();
    bool isGoodChoice(int option_choice);
    void input();
    void printHistory();
    void printRecent();
    void stop();
    void menu();
};

#endif /* WeatherStation_h */
