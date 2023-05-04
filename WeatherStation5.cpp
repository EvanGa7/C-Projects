//
//  WeatherStation5.cpp
//  FifthProjectWeatherStation
//
//  Created by Evan Gardner on 10/23/22.
//
//  This project is a weather station created to be able to print out the user inputted weather station name, current tempurature, wind speed, and the direction of the wind. As stated the program will accept inputs from the user, this will store the most recent five inputs while also ensuring that the inputs for tempurature and wind speed are both validated. The program has been optimized in a object oriented fashion to make it so all of the features are broken up into functions to improve reusability and efficency. The program's features include the prompt for the user to input a name for the program which will be stored for the duration of the run time. This is then followed by a menu with four options including Input which allows the user to input data into the program, Print Most Recent Weather Report which allows the user to print out the last weather report data they entered into the program, Print Weather History which will print the last five entries into the program or if five have not be entered then it will print out that number of entries, and finally the option to exit the program.

//initialization of the program
#include <iostream>
//string manipulation
#include <string>
//input output manipulation
#include <iomanip>
using namespace std;


//Function used to print the menu out to the user prompting for a valid option to be selected
void showMenu() {
    cout << "\nPlease Choose One Of The Following Inputs By Pressing The Desired Number Choice: ";
    cout << "\n\nOption 1: Input " << endl;
    cout << "Option 2: Print Most Recent Weather Report " << endl;
    cout << "Option 3: Print Weather History " << endl;
    cout << "Option 4: Exit " << endl;
}//end of the showMenu function


//Function used to validate whether the user chose a valid option. If option choice is one of the options it will return true and if not then it will return false
bool isGoodChoice(int option_choice) {
    bool choice_good = true;
    if (option_choice != 1 && option_choice != 2 && option_choice != 3 && option_choice != 4) {
        return choice_good == false;
    }//end of if statement
    return choice_good;
}//end of the function isGoodChoice


//Function used to shift the array of tempurature left if the number of entries exceeds five so that it is only storing the most recent five entries
void shiftArrayLeftTempurature(double tempurature[], int size) {
    for (int i = 0; i < size-1; i ++) {
        tempurature[i] = tempurature[i + 1];
    }//end of the for loop
}//end of the function shiftArrayLeftTempurature


//Function used to shift the array of wind speed left if the number of entries exceeds five so that it is only storing the most recent five entries
void shiftArrayLeftWindSpeed(int wind_speed[], int size) {
    for (int i = 0; i < size-1; i ++) {
        wind_speed[i] = wind_speed[i + 1];
    }//end of the for loop
}//end of the function shiftArrayLeftWindSpeed


//Function used to shift the array of wind direction left if the number of entries exceeds five so that it is only storing the most recent five entries
void shiftArrayLeftDirection(string direction[], int size) {
    for (int i = 0; i < size-1; i ++) {
        direction[i] = direction[i + 1];
    }//end of the for loop
}//end of the function shiftArrayLeftDirection


//Function that is used to input data into the weather station storing only the most recent five entries into the array
void input(double tempurature[], int wind_speed[], string direction[], int& array_counter, int size) {
    //This if statement will ensure that if there are less then five entries then it does not have to shift the array left and will increment the counter till five entries have been made
    if (array_counter < size) {
        //This block will prompt the user to enter a tempurature value which it will then validate and store in the array if it is an appropriate input
        cout << "Please input the tempurature you would like to use: ";
        cin >> tempurature[array_counter];
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new temperature input:  ";
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> tempurature[array_counter];
        }//end of while loop
        
        //This block will prompt the user to enter a wind speed value which it will then validate and store in the array if it is an appropriate input
        cout << "Please input the wind speed you would like to use: ";
        cin >> wind_speed[array_counter];
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new wind speed:  ";
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> wind_speed[array_counter];
        }//end of while loop
        
        //This block will prompt the user to enter a wind direction string value which it will then validate and store in the array. The array counter is used to keep track of each entry
        cout << "Please input the wind direction you would like to use: ";
        cin.ignore(1000,'\n');
        getline(cin, direction[array_counter]);
        array_counter++;
    }//end of if statement
    
    //This else if statement is used when array counter is greater than or equal to five so that the array can be shifted left for each entry moving forward so it's only five entries held
    else if (array_counter >= size) {
        //This block of code will shift the tempurature array left so that only five inputs are stored and then will ask for a user input toin the opem positon which will it then validate
        shiftArrayLeftTempurature(tempurature, size);
        cout << "Please input the tempurature you would like to use: ";
        cin >> (tempurature[array_counter-1]);
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new temperature input:  ";
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> tempurature[array_counter-1];
        }//end of while loop
        
        //This block will shift the wind speed array left so that only five inputs are stored and then will ask for a user input to store in the opem positon which will it then validate
        shiftArrayLeftWindSpeed(wind_speed, size);
        cout << "Please input the wind speed you would like to use: ";
        cin >> wind_speed[array_counter-1];
        while (cin.fail()) {
            cout << "The input that was provided is incorrect!\n" << endl;
            cout << "Please enter a new wind speed:  ";
            cin.clear();
            cin.ignore(1000,'\n');
            cin >> wind_speed[array_counter-1];
        }//end of while loop
        
        //This block of code will shift the wind direction array left so that only five inputs are stored and then will ask for a user input to store in the open position of the array
        shiftArrayLeftDirection(direction, size);
        cout << "Please input the wind direction you would like to use: ";
        cin.ignore(1000,'\n');
        getline(cin, direction[array_counter-1]);
    }//end of else if statement
}//end of the function input


//Function used to print out the most recent entry into the array showing the name of the weather station, the tempurature, wind speed, and wind direction
void printMostRecent(string weather_station, double tempurature[], int wind_speed[], string direction[], int array_counter) {
    cout << "\n\n\tThe " << weather_station << " Weather Station" << endl;
    cout << "Tempurature: " << tempurature[array_counter] << " degrees farenheit"<< endl;
    cout << "Wind Speed: " << wind_speed[array_counter] << " mph" << "\tDirection: " << direction[array_counter] << endl;
}//end of the function printMostRecent


//Function used to print out all five or the amount of entries that have been stored in the arrays showing the weather station name, the tempurature, wind speed, and wind direction
void printWeatherHistory(string weather_station, double tempurature[], int wind_speed[], string direction[], int array_counter, int size) {
    cout << "\n\n\tThe " << weather_station << " Weather Station" << endl;
        for(int i = array_counter-1; i >= 0; i--) {
            cout << "Tempurature: " << tempurature[i] << " degrees farenheit"<< endl;
            cout << "Wind Speed: " << wind_speed[i] << " mph" << "\tDirection: " << direction[i] << "\n" << endl;
        }//end of for loop
}//end of the function printWeatherHistory


//Function that will be used to execute all of the actions required for the weather station to function until the exit option is selected terminating the program
int main() {
    
    //This is the delcaration of all the variables and arrays that will be used for this weather station program
    const int size = 5;
    int array_counter = 0;
    string weather_station;
    double tempurature[size];
    int wind_speed[size];
    string direction[size];
    bool check_option_1 = false;
    int option_choice;
    
    //This block is used to prompt the user for a name of the weather station and then storing that name till it is terminated
    cout << "Please input the desired weather station name: ";
    getline( cin, weather_station);
    
    //This do while loop is used to continue the program until the user enters option four which is the one way to exit the program
    do {
        //This block is used to print the menu and then take the user's input for their option choice
        showMenu();
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
            input(tempurature, wind_speed, direction, array_counter, size);
        }//end of else if statement
            
        //This block is when option two is chosen but no input has been made yet so it will print an error and return the user to the menu
        else if (option_choice == 2 && check_option_1 == false) {
            cout << "ERROR! There Has Been No Data Input Yet Please Input Data To Have It Be Printed Out!" << endl;
        }//end of if statement
        
        //This block is option two when input has been made which will call printMostRecent to print the most recent entry that has been entered into the system
        else if (option_choice == 2 && check_option_1 == true) {
            printMostRecent(weather_station, tempurature, wind_speed, direction, array_counter-1);
        }//end of if statement
        
        //This block is when option three is chosen but no input has been made yet so it will print an error and return the user to the menu
        else if (option_choice == 3 && check_option_1 == false) {
            cout << "ERROR! There Has Been No Data Input Yet Please Input Data To Have It Be Printed Out!" << endl;
        }//end of if statement
        
        //This block is option three when input has been made which will call printWeatherHistory to print all of the most recent entries up to five
        else if (option_choice == 3 && check_option_1 == true) {
            printWeatherHistory(weather_station, tempurature, wind_speed, direction, array_counter, size);
        }//end of if statement
    } while (option_choice != 4);
    
    return 0;
}//end of main function
