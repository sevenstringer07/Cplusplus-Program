#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

/**
 * Constructor - Initializes the GroceryTracker with file names
 * @param inputFile - Name of the input file to read from
 * @param backupFile - Name of the backup file to write to
 */
GroceryTracker::GroceryTracker(std::string inputFile, std::string backupFile) {
    inputFileName = inputFile;
    backupFileName = backupFile;
}

/**
 * LoadDataFromFile - Reads items from input file and counts frequencies
 * @return true if successful, false otherwise
 */
bool GroceryTracker::LoadDataFromFile() {
    std::ifstream inputFile(inputFileName);
    
    // Check if file opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << inputFileName << std::endl;
        return false;
    }
    
    std::string item;
    
    // Read each item from the file and increment its frequency
    while (inputFile >> item) {
        // Increment frequency (map creates entry with value 0 if key doesn't exist)
        itemFrequencies[item]++;
    }
    
    inputFile.close();
    return true;
}

/**
 * SaveFrequencyData - Writes frequency data to backup file
 * @return true if successful, false otherwise
 */
bool GroceryTracker::SaveFrequencyData() {
    std::ofstream outputFile(backupFileName);
    
    // Check if file opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create backup file: " << backupFileName << std::endl;
        return false;
    }
    
    // Write each item and its frequency to the file
    for (const auto& pair : itemFrequencies) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }
    
    outputFile.close();
    return true;
}

/**
 * GetItemFrequency - Returns the frequency of a specific item
 * @param itemName - Name of the item to search for
 * @return Frequency count (0 if item not found)
 */
int GroceryTracker::GetItemFrequency(std::string itemName) {
    // Find the item in the map
    auto it = itemFrequencies.find(itemName);
    
    // Return frequency if found, otherwise return 0
    if (it != itemFrequencies.end()) {
        return it->second;
    }
    return 0;
}

/**
 * DisplayItemFrequencies - Displays all items with their numeric frequencies
 */
void GroceryTracker::DisplayItemFrequencies() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "   Item Frequency List" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Display each item and its frequency
    for (const auto& pair : itemFrequencies) {
        std::cout << std::left << std::setw(20) << pair.first 
                  << pair.second << std::endl;
    }
    
    std::cout << "========================================\n" << std::endl;
}

/**
 * DisplayHistogram - Displays a text-based histogram using asterisks
 */
void GroceryTracker::DisplayHistogram() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "   Item Frequency Histogram" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Display each item with asterisks representing frequency
    for (const auto& pair : itemFrequencies) {
        std::cout << std::left << std::setw(20) << pair.first;
        
        // Print asterisks equal to frequency
        for (int i = 0; i < pair.second; i++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    std::cout << "========================================\n" << std::endl;
}

/**
 * GetUniqueItemCount - Returns the number of unique items
 * @return Number of unique items tracked
 */
int GroceryTracker::GetUniqueItemCount() {
    return itemFrequencies.size();
}
