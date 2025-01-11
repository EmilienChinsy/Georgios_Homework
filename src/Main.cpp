#include <iostream>
#include <string>
#include <limits>
#include "requests.hpp"

using namespace std;

int main(){
    vector<Dishes> dishes;
    const int max_dishes = 500;
    int userInput;
    bool ending;
    // cout outputs text in the console
    cout << "Welcome to your very own dish storing database!" << endl;
    cout << "This database exists to allow you to store your favorite dishes, a link to their recipes, how healthy they are on a scale from 1 to 5 and a rating from 1 to 5 where 1 is unhealthy/terrible and five is very healthy/amazing"<< endl;
    cout << "Important info: Never put spaces in your inputs, for example inputs Pulled_pork instead of Pulled pork" << endl;
    cout << "For now, here are the actions you can take:" << endl;
    cout << "1. Display all dishes  " << endl;
    cout << "2. Add a dish  " << endl;
    cout << "3. Display a dishes using it's name" << endl;
    cout << "4. Edit a dish using it's name" << endl;
    cout << "5. Remove a dish using it's name" << endl;
    cout << "6. Sort the dishes" << endl;
    cout << "7. End the program" << endl;
    cout << "Type the number of the action you want to take in the console" << endl;
    ending = false;
    while (!ending){
        cout << "Enter your choice: ";
        // cin waits for the users input.
        cin >> userInput;
        // if the input that the user inputs is not correct, for example if it is a string a userInput is an integer
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input, please enter a number corresponding an action." << endl;
        } else {
            switch (userInput) {
                case 1:
                    for (auto &currentDish : dishes)    
                        currentDish.display();
                    if (dishes.size() == 0) {
                        cout << "you have not created any dishes yet" << endl;
                    }
                    break;
                case 2:
                    addDish(dishes);
                    break;
                case 3:
                    retrieveDish(dishes);
                    break;
                case 4:
                    updateDish(dishes);
                    break;
                case 5:
                    removeDish(dishes);
                    break;
                case 6:
                    sortDishes(dishes);
                    break;
                case 7:
                    cout << "Ending the program."<< endl;
                    ending = true;
                    break;
                default:
                    cout << "Please enter a number that corresponding to an action." << endl;
            }
        }
    }
    return 0;
}