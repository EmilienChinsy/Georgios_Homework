#include <iostream>
#include <string>
#include <vector>
#include "Dishes.hpp"

#include <iostream>
#include <string>
#include <vector>

// Merge sort implementation for sorting Dishes the inputed value
void merge(vector<Dishes> &dishes, int left, int mid, int right, int sortValue) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Dishes> leftPart(n1);
    vector<Dishes> rightPart(n2);

    for (int i = 0; i < n1; ++i)
        leftPart[i] = dishes[left + i];
    for (int j = 0; j < n2; ++j)
        rightPart[j] = dishes[mid + 1 + j];

    int i = 0, j = 0, k = left;
    switch (sortValue) {
        case 1:
            while (i < n1 && j < n2) {
                if (leftPart[i].getRating() <= rightPart[j].getRating()) {
                    dishes[k] = leftPart[i];
                    ++i;
                } else {
                    dishes[k] = rightPart[j];
                    ++j;
                }
                ++k;
            }
        case 2:
            while (i < n1 && j < n2) {
                if (leftPart[i].getHealthValue() <= rightPart[j].getHealthValue()) {
                    dishes[k] = leftPart[i];
                    ++i;
                } else {
                    dishes[k] = rightPart[j];
                    ++j;
                }
                ++k;
            }

    }

    while (i < n1) {
        dishes[k] = leftPart[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        dishes[k] = rightPart[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<Dishes> &dishes, int left, int right, int sortValue) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(dishes, left, mid, sortValue);
    mergeSort(dishes, mid + 1, right, sortValue);
    merge(dishes, left, mid, right, sortValue);
    
}


// Main sorting function to choose the attribute
void sortDishes(vector<Dishes> &dishes) {
    int userInput;
    cout << "The dishes will be sorting from lowest to highest" << endl;
    cout << "Select the attribute you want to sort by:" << endl;
    cout << "1. Rating" << endl;
    cout << "2. Healthiness" << endl;
    cin >> userInput;

    switch (userInput) {
        case 1:
            mergeSort(dishes, 0, dishes.size()-1, userInput);
            cout << "Dishes sorted by Rating successfully!\n";
            break;
        case 2:
            mergeSort(dishes, 0, dishes.size()-1, userInput);
            cout << "Dishes sorted by Healthiness successfully!\n";
            break;
        default:
            cout << "Invalid choice.\n";
            return;
    }

    // Debugging message to confirm we are back to the main loop
    cout << "Returning to main menu...\n";
}

// This function allows the user to add new dishes to the vector
void addDish(vector<Dishes> &dishes){
    string name;
    string link;
    int healthValue;
    int rating;

    cout << "Enter the name of your dish: ";
    cin >> name;
    cout << "Enter a link a recipe for your dish: ";
    cin >> link;
    cout << "Enter the healthiness value of your dish on a scale from 1 to 5, 1 being awful and 5 being perfect: ";
    cin >> healthValue;
    cout << "Rate the dish on a scale from 1 to 5, 1 being awful and 5 being perfect: ";
    cin >> rating;

    dishes.push_back(Dishes(name, link, healthValue, rating));
    cout << "Dish added successfully!" << endl;
}

// This function retrieves a dish from the vector, we use the name of the dish to find it
void retrieveDish(vector<Dishes> &dishes) {
    string name;
    cout << "Enter the name of your dish: ";
    cin >> name;

    for (Dishes &dishes : dishes) {
        if (dishes.getName() == name) {
            dishes.display();
            return;
        }
    }
    cout << "Dish not found.\n";
}

// This function updates a dishes's information in the vector
void updateDish(vector<Dishes> &dishes) {
    string name;
    cout << "Enter the name of your dish: ";
    cin >> name;

    for (Dishes &dishes : dishes) {
        if (dishes.getName() == name) {
            string name;
            string link;
            int healthValue;
            int rating;

            cout << "Select the attribute you want to update:" << endl;
            cout << "1. Name" << endl;
            cout << "2. Link" << endl;
            cout << "3. Health value" << endl;
            cout << "4. Rating" << endl;
            cout << "5. All" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter a new name for your dish: ";
                    cin >> name;
                    dishes.setName(name);
                    break;
                case 2:
                    cout << "Enter a new link for your dish: ";
                    cin >> link;
                    dishes.setLink(link);
                    break;
                case 3:
                    cout << "Enter a new health value for your dish: ";
                    cin >> healthValue;
                    dishes.setHealthValue(healthValue);
                    break;
                case 4:
                    cout << "Enter a new rating for your dish: ";
                    cin >> rating;
                    dishes.setRating(rating);
                    break;
                case 5:
                    cout << "Enter a new name for your dish: ";
                    cin >> name;
                    cout << "Enter a new link for your dish: ";
                    cin >> link;
                    cout << "Enter a new health value for your dish: ";
                    cin >> healthValue;
                    cout << "Enter a new rating for your dish: ";
                    cin >> rating;

                    dishes.setName(name);
                    dishes.setLink(link);
                    dishes.setHealthValue(healthValue);
                    dishes.setRating(rating);
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    return;
            }

            cout << "Dish updated successfully!" << endl;
            return;
        }
    }

    cout << "Dish not found." << endl;
}

// This function removes a Dish from the vector
void removeDish(vector<Dishes> &dishes){
    string name;

    cout << "Enter the name of the dish you wish to delete: ";
    cin >> name;

    for (auto currentDish = dishes.begin(); currentDish != dishes.end(); ++currentDish) {
        if (currentDish->getName() == name) {
            dishes.erase(currentDish);
            cout << "Dish deleted successfully!" << endl;
            return;  
        }
        cout << "Dish not found or does not exist." << endl;
    }
}