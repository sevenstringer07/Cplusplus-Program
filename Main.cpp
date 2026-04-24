#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

/**
 * DisplayMenu - Displays the main menu options
 */
void DisplayMenu() {
    cout << "\n========================================" << endl;
    cout << "   Corner Grocer Item Tracking Menu" << endl;
    cout << "========================================" << endl;
    cout << "1. Search for item frequency" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display frequency histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice (1-4): ";
}

/**
 * GetValidMenuChoice - Gets and validates menu choice from user
 * @return Valid menu choice (1-4)
 */
int GetValidMenuChoice() {
    int choice;
    
    while (true) {
        if (cin >> choice) {
            // Check if choice is in valid range
            if (choice >= 1 && choice <= 4) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return choice;
            }
            else {
                cout << "Invalid choice. Please enter a number between 1 and 4: ";
            }
        }
        else {
            // Handle non-integer input
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/**
 * SearchItemFrequency - Handles menu option 1 (search for specific item)
 * @param tracker - Reference to GroceryTracker object
 */
void SearchItemFrequency(GroceryTracker& tracker) {
    string itemName;
    
    cout << "\nEnter the item name to search for: ";
    cin >> itemName;
    
    // Get frequency of the item
    int frequency = tracker.GetItemFrequency(itemName);
    
    cout << "\n" << itemName << " appears " << frequency << " time(s)." << endl;
}

/**
 * Main function - Entry point of the program
 */
int main() {
    // File names
    const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
    const string BACKUP_FILE = "frequency.dat";
    
    // Create GroceryTracker object
    GroceryTracker tracker(INPUT_FILE, BACKUP_FILE);
    
    cout << "========================================" << endl;
    cout << "   Corner Grocer Item Tracker" << endl;
    cout << "========================================" << endl;
    
    // Load data from input file
    cout << "\nLoading data from " << INPUT_FILE << "..." << endl;
    if (!tracker.LoadDataFromFile()) {
        cerr << "Failed to load data. Program will exit." << endl;
        return 1;
    }
    
    cout << "Data loaded successfully!" << endl;
    
    // Create backup file
    cout << "Creating backup file " << BACKUP_FILE << "..." << endl;
    if (!tracker.SaveFrequencyData()) {
        cerr << "Warning: Failed to create backup file." << endl;
    }
    else {
        cout << "Backup file created successfully!" << endl;
    }
    
    // Main program loop
    int choice;
    bool running = true;
    
    while (running) {
        DisplayMenu();
        choice = GetValidMenuChoice();
        
        switch (choice) {
            case 1:
                // Search for specific item
                SearchItemFrequency(tracker);
                break;
                
            case 2:
                // Display all frequencies
                tracker.DisplayItemFrequencies();
                break;
                
            case 3:
                // Display histogram
                tracker.DisplayHistogram();
                break;
                
            case 4:
                // Exit program
                cout << "\nThank you for using Corner Grocer Item Tracker!" << endl;
                cout << "Goodbye!" << endl;
                running = false;
                break;
                
            default:
                cout << "Unexpected error occurred." << endl;
                break;
        }
    }
    
    return 0;
}
