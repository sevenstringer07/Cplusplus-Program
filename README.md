# Cplusplus-Program
Portfolio of C++ projects for CS coursework

# Corner Grocer Item Tracking Program

## Project Summary

This C++ program was developed for Corner Grocer to analyze the frequency of items purchased throughout the day. The business problem it solves is helping the store understand which produce items are most popular so they can optimize their layout and inventory management. The program reads purchase records from a text file (CS210_Project_Three_Input_File.txt), tracks how often each item appears, and provides three different ways to view this data: searching for specific items, displaying a complete frequency list, and showing a visual histogram. The program also automatically creates a backup file (frequency.dat) for data persistence.

## Reflection

### What Did I Do Particularly Well?

I'm particularly proud of the code organization and documentation in this project. I implemented strong object-oriented design principles by creating a well-encapsulated `GroceryTracker` class with clear separation between the interface (.h file) and implementation (.cpp file). Every function includes detailed comments explaining its purpose, parameters, and return values, which makes the code easy to understand for anyone reviewing it.

I also created robust input validation in the `GetValidMenuChoice()` function that gracefully handles both invalid numbers and non-numeric input without crashing. The error handling uses `cin.clear()` and `cin.ignore()` to properly reset the input stream, ensuring the program remains stable even with unexpected user behavior. Additionally, I chose appropriate data structures - using `std::map` provides efficient O(log n) lookups and automatically keeps items in alphabetical order, which enhances the user experience.

### Where Could I Enhance My Code?

There are several areas where the code could be improved:

**Case-Insensitive Search**: Currently, "Apples" and "apples" would be treated as different items. I could enhance the `LoadDataFromFile()` and `GetItemFrequency()` functions to convert all items to lowercase, making the program more user-friendly and the data more accurate.

**Exception Handling**: Instead of returning boolean values from file operations, I could implement try-catch blocks with custom exceptions. This would provide more detailed error information and follow modern C++ best practices for error management.

**Data Validation**: I could add validation to ensure the input file contains only valid item names (no numbers or special characters), which would make the program more robust against corrupted data files.

These improvements would make the code more efficient by preventing duplicate entries due to case variations, more secure by validating data before processing, and more maintainable by providing clearer error messages for debugging.

### Which Pieces Did I Find Most Challenging?

The most challenging aspect was implementing proper input validation for the menu system. I needed to handle not just invalid menu numbers (like choosing option 5 when only 1-4 exist), but also completely non-numeric input like typing "abc" instead of a number. The tricky part was that invalid input can break the `cin` stream, causing an infinite loop if not handled correctly.

I overcame this by researching C++ input stream management and learning about `cin.clear()` to reset error flags and `cin.ignore()` to flush the input buffer. I tested various invalid inputs to ensure the program remained stable. Stack Overflow and cppreference.com became valuable resources in my support network for understanding stream state management.

Another challenge was working with the `std::map` container and its iterators. Initially, I wasn't sure how to safely check if an item exists before accessing it. I learned to use the `find()` method and compare against `end()` to avoid creating unwanted entries in the map, which was important for maintaining data accuracy.

### What Skills Are Particularly Transferable?

Several skills from this project will be valuable in future coursework and professional work:

**Object-Oriented Design**: The principles of encapsulation, separation of concerns, and modular design apply to virtually any programming language - whether I'm working in Java, Python, or C#, these concepts remain fundamental.

**Data Structure Selection**: Understanding when to use a map versus a vector or array, and considering time complexity (O(log n) lookups) demonstrates algorithmic thinking that applies to any programming challenge.

**File I/O Operations**: Reading from files, writing to files, and handling file errors are common requirements in real-world applications, from data analysis to web servers.

**Input Validation**: Every user-facing application needs to handle invalid input gracefully. The techniques I used here - validating ranges, handling type mismatches, and providing clear error messages - are universal best practices.

**Code Documentation**: The habit of writing clear comments and using descriptive names makes code maintainable, which is critical in team environments and professional software development.

### How Did I Make the Program Maintainable, Readable, and Adaptable?

I focused on several key practices to ensure code quality:

**Meaningful Names**: I used clear, descriptive names like `GetItemFrequency()` instead of abbreviated names like `GetFreq()`. Variables like `itemFrequencies` immediately convey their purpose without needing to read comments.

**Consistent Formatting**: I followed consistent naming conventions (PascalCase for functions, camelCase for variables) and used proper indentation throughout, making the code visually scannable.

**Modular Design**: The `GroceryTracker` class handles all data management, while `Main.cpp` handles the user interface. This separation means I could replace the console interface with a GUI without touching the core business logic, or reuse the `GroceryTracker` class in a completely different program.

**Constants for Configuration**: File names are stored in constants (`INPUT_FILE`, `BACKUP_FILE`) in Main.cpp, making it easy to change data sources without modifying the core logic.

**Comprehensive Documentation**: Every function has a comment block explaining what it does, what parameters it takes, and what it returns. Complex logic includes inline comments explaining the "why" behind decisions.

**Single Responsibility Principle**: Each function does one thing well. `LoadDataFromFile()` only loads data, `DisplayHistogram()` only displays the histogram, etc. This makes testing, debugging, and future modifications much easier.

These practices mean that six months from now, or for another developer reviewing my code, the purpose and functionality will be immediately clear, and modifications can be made with confidence.

---

## Technical Details

### Program Architecture
The program uses object-oriented design with three main components:
- **GroceryTracker.h** - Header file defining the class interface
- **GroceryTracker.cpp** - Implementation of class methods  
- **Main.cpp** - Main program with user interface and menu system

### Key Features
1. **Search for Item Frequency** - Look up how many times a specific item was purchased
2. **Display All Frequencies** - View complete list with numeric counts
3. **Display Histogram** - Visual representation using asterisks (*)
4. **Automatic Backup** - Creates frequency.dat file on startup
5. **Input Validation** - Handles invalid menu choices gracefully

### Data Structures Used
- **std::map<std::string, int>** - Primary data structure
  - Provides O(log n) lookup efficiency
  - Automatically maintains alphabetical order
  - Prevents duplicate keys

### File Operations
- **Input File**: CS210_Project_Three_Input_File.txt
  - Format: One item per line
  - Represents chronological purchase order
  
- **Backup File**: frequency.dat
  - Format: ItemName Frequency (space-separated)
  - Automatically created on program startup
  - Used for data persistence

### Menu Options Explained
1. **Option 1**: Enter item name to see its purchase count
2. **Option 2**: See all items with their frequencies in a formatted list
3. **Option 3**: See visual histogram where each * = one purchase
4. **Option 4**: Exit the program with goodbye message

## How to Compile and Run

### Using Visual Studio:
