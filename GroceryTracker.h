#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <string>
#include <map>

/**
 * GroceryTracker class
 * Handles tracking and analyzing grocery item frequencies from an input file
 */
class GroceryTracker {
private:
    // Map to store item names and their frequencies
    std::map<std::string, int> itemFrequencies;
    
    // File paths
    std::string inputFileName;
    std::string backupFileName;

public:
    // Constructor
    GroceryTracker(std::string inputFile, std::string backupFile);
    
    // Load data from input file
    bool LoadDataFromFile();
    
    // Save frequency data to backup file
    bool SaveFrequencyData();
    
    // Get frequency of a specific item
    int GetItemFrequency(std::string itemName);
    
    // Display all items with their frequencies
    void DisplayItemFrequencies();
    
    // Display histogram of all items
    void DisplayHistogram();
    
    // Get total number of unique items
    int GetUniqueItemCount();
};

#endif
