//
//  WeatherStation4.cpp
//  ThirdProjectWeatherStation
//
//  Created by Evan Gardner on 10/09/22.
//
// This project is a Weather Station that prints out the name of the station, current temperature, wind speed, and the direction of the wind. This is with the addition of being able to input the different elements of the weather station as previously named and check whether the inputs are valid. The addition of a menu has also been added to make it so the user can input values, print values that have been previously entered, and exit the program when they are finished using the system. The changes that have been implemented is the refactored code to make it so many of the operations within the program operate off functions that can be reused for other tasks.

//initialization of the program
#include <iostream>
//string manipulation
#include <string>
//input output manipulation
#include <iomanip>
using namespace std;

//This is the function that is called when the menu is printed out prompting the user to select a valid option
void showMenu() {
    cout << "\nPlease Choose One Of The Following Inputs By Pressing The Desired Number Choice: ";
    cout << "\n\nOption 1: Input " << endl;
    cout << "Option 2: Print " << endl;
    cout << "Option 3: Exit " << endl;
}//end of the showMenu function

//----------------------------------------------------------------------------------------------

//This is a function created to check whether the user made a valid choice and if so allow the user to continue with that choice otherwise it will return a false statement and prompt the user to select a new option from the menu
bool isGoodChoice(int option_choice) {
    bool choice_good = true;
    if (option_choice != 1 && option_choice != 2 && option_choice != 3) {
        return choice_good == false;
    }//end of if statement
    return choice_good;
}//end of the function isGoodChoice

//----------------------------------------------------------------------------------------------

//This is the function that will be called when the user is looking to input data into the weather station
void input(double& tempurature, int& wind_speed, string& direction) {
    
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
    
    //--------------------------------------------------------------------------------------
    
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
    
    //--------------------------------------------------------------------------------------
    
    //This is the portion of code asking for the wind direction input for the wether station
    cout << "Please input the wind direction you would like to use: ";
    cin.ignore(1000,'\n');
    getline(cin, direction);
}//end of the function input

//----------------------------------------------------------------------------------------------

//This is the function that will be called when the user is looking to print out the data that has been enetered into the weather station
void print(string weather_station, double tempurature = 0.0, int wind_speed = 0, string direction = "NULL") {
    //This is the portion of code that prints the weather stations information for the user
    cout << "\n\n\tThe " << weather_station << " Weather Station" << endl;
    cout << "Tempurature: " << tempurature << " degrees farenheit"<< endl;
    cout << "Wind Speed: " << wind_speed << " mph" << "\tDirection: " << direction << endl;
}//end of the function print

//----------------------------------------------------------------------------------------------

//This is the main function that will execute all of the following actions until the program is exited by the user
int main() {
    
    //This is the declaration of the four variables that will be used for the weather station
    string weather_station;
    double tempurature = 0.0;
    int wind_speed = 0;
    string direction = "NULL";
    bool check_option_1 = false;

    //This is the variable used to hold the results of the user input for the menu
    int option_choice;
    
//----------------------------------------------------------------------------------------------
    
        //This is the portion of code asking for the name input for the wether station
        cout << "Please input the desired weather station name: ";
        getline( cin, weather_station);
        
//----------------------------------------------------------------------------------------------
    
    //This is the beginning of the do while loop that will continue the program of asking for the user input and if they want it printed until they choose the option to exit
    do {
        
        //This is the portion of code that will collect the option choice from the menu
        showMenu();
        cin >> option_choice;
        
        //--------------------------------------------------------------------------------------
        
        //Portion of the code that will check to make sure the input is valid or else it make the user enter a new input
        if (isGoodChoice(option_choice) == false) {
            cout << "Error Invalid Option! Please Choose A Valid Option! \n" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }//end of if statement
            
        //--------------------------------------------------------------------------------------
        
        //This is the beginning of the input option for the user which will ask the user for the all information needed for the weather station and will validate the inputs entered. This will also change the option taht will check if option 1 was chosen yet so that it can be printed out
        else if (option_choice == 1) {
            check_option_1 = true;
            input(tempurature, wind_speed, direction);
        }//end of if statement
        
        //--------------------------------------------------------------------------------------
            
            //This is the portion of code that will look at if there has been any input within the program yet before printing and if not it will ask the user to make an input before the output can be presented to the user
            else if (option_choice == 2 && check_option_1 == false) {
                cout << "ERROR! There Has Been No Data Input Yet Please Input Data To Have It Be Printed Out!" << endl;
            }//end of if statement
        
            //This is the portion of the code that will make sure there is input and if the user chose to print and if they did it will print the results they entered
            else if (option_choice == 2 && direction != "NULL") {
                print(weather_station, tempurature, wind_speed, direction);
            }//end of if statement
        
    } while (option_choice != 3);
        
//----------------------------------------------------------------------------------------------
        
    return 0;
}//end of main function

