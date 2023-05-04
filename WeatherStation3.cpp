//
//  WeatherStation3.cpp
//  ThirdProjectWeatherStation
//
//  Created by Evan Gardner on 9/24/22.
//
// This project is a Weather Station that prints out the name of the station, current temperature, wind speed, and the direction of the wind. This is with the addition of being able to input the different elements of the weather station as previously named and check whether the inputs are valid. The addition of a menu has also been added to make it so the user can input values, print values that have been previously entered, and exit the program when they are finished using the system.

#include <iostream>
//string manipulation
#include <string>
//input output manipulation
#include <iomanip>
using namespace std;

int main() {
    
    //This is the declaration of the four variables that will be used for the weather station
    string weather_station;
    double tempurature = 0.0;
    int wind_speed = 0;
    string direction = "NULL";

    //This is the variable used to hold the results of the user input for the menu
    int option_choice;
    
//----------------------------------------------------------------------------------------------
    
        //This is the portion of code asking for the name input for the wether station
        cout << "Please input the desired weather station name: ";
        getline( cin, weather_station);
        
//----------------------------------------------------------------------------------------------
    
    //This is the beginning of the do while loop that will continue the program of asking for the user input and if they want it printed until they choose the option to exit
    do {
           
        //This is the portion of code that will collect the option choice for the menu
        cout << "\nPlease Choose One Of The Following Inputs By Pressing The Desired Number Choice: ";
        cout << "\n\nOption 1: Input " << endl;
        cout << "Option 2: Print " << endl;
        cout << "Option 3: Exit " << endl;
        cin >> option_choice;
        
        //--------------------------------------------------------------------------------------
        
        //Portion of the code that will check to make sure the input is valid or else it make the user enter a new input
        if (option_choice != 1 && option_choice != 2 && option_choice != 3) {
            cout << "Error Invalid Option! Please Choose A Valid Option! \n" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }//end of if statement

        //--------------------------------------------------------------------------------------
        
        //This is the beginning of the input option for the user which will ask the user for the all information needed for the weather station and will validate the inputs entered
        if (option_choice == 1) {
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
            
            //----------------------------------------------------------------------------------
            
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
            
            //----------------------------------------------------------------------------------
            
            //This is the portion of code asking for the wind direction input for the wether station
            cout << "Please input the wind direction you would like to use: ";
            cin.ignore(1000,'\n');
            getline(cin, direction);
        }//end of if statement
        
        //--------------------------------------------------------------------------------------
            
            //This is the portion of code that will look at if there has been any input within the program yet before printing and if not it will ask the user to make an input before the output can be presented to the user
            if (option_choice == 2 && direction == "NULL") {
                cout << "ERROR! There Has Been No Data Input Yet Please Input Data To Have It Be Printed Out!" << endl;
            }//end of if statement
        
            //This is the portion of the code that will make sure there is input and if the user chose to print and if they did it will print the results they entered
            if (option_choice == 2 && direction != "NULL") {
                //This is the portion of code that prints the weather stations information for the user
                cout << "\n\n\tThe " << weather_station << " Weather Station" << endl;
                cout << "Tempurature: " << tempurature << " degrees farenheit"<< endl;
                cout << "Wind Speed: " << wind_speed << " mph" << "\tDirection: " << direction << endl;
            }//end of if statement
        
    } while (option_choice != 3);
        
//----------------------------------------------------------------------------------------------
        
    return 0;
}//end of main function
