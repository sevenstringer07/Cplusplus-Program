#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <string>
#include <map>

using namespace std;

/**
 * GroceryTracker class
 * Manages item frequency tracking for the Corner Grocer
 * Provides functionality to read input, generate reports, and create backup files
 */
class GroceryTracker {
private:
    // Map to store item names and their frequencies
    map<string, int> itemFrequency;
    
    // Input file name constant
    const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
    
    // Backup file name constant
    const string BACKUP_FILE = "frequency.dat";

public:
    // Constructor
    GroceryTracker();
    
    // Destructor
    ~GroceryTracker();
    
    /**
     * Loads items from the input file and populates the frequency map
     * @return true if successful, false otherwise
     */
    bool LoadInputFile();
    
    /**
     * Creates a backup file with item frequencies
     * @return true if successful, false otherwise
     */
    bool CreateBackupFile();
    
    /**
     * Searches for a specific item and returns its frequency
     * @param itemName The name of the item to search for
     * @return The frequency of the item (0 if not found)
     */
    int GetItemFrequency(const string& itemName);
    
    /**
     * Prints all items with their numeric frequencies
     */
    void PrintAllFrequencies();
    
    /**
     * Prints a histogram of all items using asterisks
     */
    void PrintHistogram();
};

#endif
