#include <iostream>
#include <string>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

/**
 * Displays the main menu options to the user
 */
void DisplayMenu() {
    cout << "\n========================================" << endl;
    cout << "   Corner Grocer Item-Tracking System" << endl;
    cout << "========================================" << endl;
    cout << "1. Search for item frequency" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display frequency histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice (1-4): ";
}

/**
 * Validates and reads an integer input from the user
 * @return A valid integer input
 */
int GetValidMenuChoice() {
    int choice;
    
    // Input validation loop
    while (!(cin >> choice)) {
        // Clear error flag
        cin.clear();
        
        // Discard invalid input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "Invalid input. Please enter a number (1-4): ";
    }
    
    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return choice;
}

/**
 * Handles Menu Option 1: Search for a specific item
 * @param tracker Reference to the GroceryTracker object
 */
void SearchItemFrequency(GroceryTracker& tracker) {
    string itemName;
    
    cout << "\nEnter the item name to search: ";
    getline(cin, itemName);
    
    // Get the frequency for the specified item
    int frequency = tracker.GetItemFrequency(itemName);
    
    if (frequency > 0) {
        cout << "\nItem: " << itemName << endl;
        cout << "Frequency: " << frequency << endl;
    }
    else {
        cout << "\nItem \"" << itemName << "\" not found in records." << endl;
    }
}

/**
 * Main function - Entry point of the program
 */
int main() {
    // Create GroceryTracker object (loads data and creates backup automatically)
    GroceryTracker tracker;
    
    int choice;
    bool running = true;
    
    // Main program loop
    while (running) {
        DisplayMenu();
        choice = GetValidMenuChoice();
        
        // Process user's menu choice
        switch (choice) {
            case 1:
                // Menu Option 1: Search for specific item
                SearchItemFrequency(tracker);
                break;
                
            case 2:
                // Menu Option 2: Display all frequencies
                tracker.PrintAllFrequencies();
                break;
                
            case 3:
                // Menu Option 3: Display histogram
                tracker.PrintHistogram();
                break;
                
            case 4:
                // Menu Option 4: Exit program
                cout << "\nThank you for using Corner Grocer Item-Tracking System!" << endl;
                cout << "Goodbye!\n" << endl;
                running = false;
                break;
                
            default:
                // Handle invalid menu choices
                cout << "\nInvalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    }
    
    return 0;
}
