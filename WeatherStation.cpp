//
//  WeatherStation.cpp
//  EighthWeatherStationProject
//
//  Created by Evan Gardner on 12/5/22.
//

#include <stdio.h>

#include "WeatherStation.h"
#include "WeatherReading.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

WeatherStation::WeatherStation(string name1, int size1):WeatherReading(){
    history = new WeatherReading[size];
    name = name1;
    size = size1;
    counter = 0;
    running = true;
    option_choice = 0;
    check_option_1 = false;
}

WeatherStation::~WeatherStation(){
    delete [] history;
    history = NULL;
}

//Function used to validate whether the user chose a valid option. If option choice is one of the options it will return true and if not then it will return false
bool WeatherStation::isGoodChoice(int option_choice) {
    bool choice_good = true;
    if (option_choice != 1 && option_choice != 2 && option_choice != 3 && option_choice != 4) {
        return choice_good == false;
    }//end of if statement
    return choice_good;
}//end of the function isGoodChoice

void WeatherStation::input(){
    double temp;
    int wind1;
    string wind2;
    if (counter < size) {
        cout << "Please input the tempurature you would like to use: ";
        cin >> temp;
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new temperature input:  ";
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> temp;
        }//end of while loop

        cout << "Please input the wind speed you would like to use: ";
        cin >> wind1;
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new wind speed:  ";
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> wind1;
        }//end of while loop

        cout << "Please input the wind direction you would like to use: ";
        cin.ignore(1000,'\n');
        getline(cin, wind2);
        
        WeatherReading reading (temp, wind1, wind2);
        history[counter] = reading;
        counter++;
    }//end of if statement

    else if (counter >= size) {
        cout << "Please input the tempurature you would like to use: ";
        cin >> temp;
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new temperature input:  ";
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> temp;
        }//end of while loop
        
        cout << "Please input the wind speed you would like to use: ";
        cin >> wind1;
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new wind speed:  ";
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> wind1;
        }//end of while loop

        cout << "Please input the wind direction you would like to use: ";
        cin.ignore(1000,'\n');
        getline(cin, wind2);
        
        WeatherReading reading (temp, wind1, wind2);
        for (int i = 0; i < size-1; i ++) {
            history[i] = history[i + 1];
        }//end of the for loop
        history[size-1] = reading;
    }//end of else if statement
}

void WeatherStation::printHistory(){
    cout << "\n\n\tThe " << name << " Weather Station" << endl;
        for(int i = counter-1; i >= 0; i--) {
            history[i].print();
        }//end of for loop
}

void WeatherStation::printRecent(){
    cout << "\n\n\tThe " << name << " Weather Station" << endl;
    history[counter-1].print();
}

void WeatherStation::stop(){
    running = false;
}

void WeatherStation::menu(){
    do {
        //This block is used to print the menu and then take the user's input for their option choice
        cout << "\nPlease Choose One Of The Following Inputs By Pressing The Desired Number Choice: ";
        cout << "\n\nOption 1: Input " << endl;
        cout << "Option 2: Print Most Recent Weather Report " << endl;
        cout << "Option 3: Print Weather History " << endl;
        cout << "Option 4: Exit " << endl;
        cin >> option_choice;
        
        //This block will check to ensure that the user made a valid choice and if they didn't it will return them to them menu to make a new choice
        if (isGoodChoice(option_choice) == false) {
            cout << "Error Invalid Option! Please Choose A Valid Option! \n" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }//end of if statement
        
        //This block is option one that will change the check for input to true and will call the input function to enter data that will be stored into each array for each report
        else if (option_choice == 1) {
            check_option_1 = true;
            input();
        }//end of else if statement
        
        //This block is when option two is chosen but no input has been made yet so it will print an error and return the user to the menu
        else if (option_choice == 2 && check_option_1 == false) {
            cout << "ERROR! There Has Been No Data Input Yet Please Input Data To Have It Be Printed Out!" << endl;
        }//end of if statement
        
        //This block is option two when input has been made which will call printMostRecent to print the most recent entry that has been entered into the system
        else if (option_choice == 2 && check_option_1 == true) {
            printRecent();
        }//end of if statement
        
        //This block is when option three is chosen but no input has been made yet so it will print an error and return the user to the menu
        else if (option_choice == 3 && check_option_1 == false) {
            cout << "ERROR! There Has Been No Data Input Yet Please Input Data To Have It Be Printed Out!" << endl;
        }//end of if statement
        
        //This block is option three when input has been made which will call printWeatherHistory to print all of the most recent entries up to the size of the array in new to old order
        else if (option_choice == 3 && check_option_1 == true) {
            printHistory();
        }//end of if statement
        
        else if (option_choice == 4) {
            stop();
            WeatherStation::~WeatherStation();
        }//end of if statement
    }while(running == true);
}
