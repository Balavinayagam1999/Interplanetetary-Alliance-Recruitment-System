#include <iostream>         // For input/output using cout, cin, etc.
#include <fstream>          // For file input/output using ifstream
#include <vector>           // For using std::vector container
#include "human.h"          // Header file for human class
#include "alien.h"          // Header file for alien class
#include "crew_sort.h"      // Header file for sorting helper functions

using namespace std;        // Use the standard namespace (std::) by default

// ============================================================
// Global Vectors
// ============================================================

// Stores all Human crew members read from the file
vector<human> humanCrew;    

// Stores all Alien crew members read from the file
vector<alien> alienCrew;    

// Stores sorted Human results (so we don't modify the original vector)
vector<human> sortedHumans; 

// Stores sorted Alien results (so we don't modify the original vector)
vector<alien> sortedAliens; 


// ============================================================
// Function Prototypes
// ============================================================

// Loads data from the human and alien text files
void uploadingFiles();      

// Menu option: sort humans by a single chosen field
void singleFieldSortHuman();

// Menu option: sort aliens by a single chosen field
void singleFieldSortAlien();

// Menu option: overall multi-key sort for humans
void overallSortHuman();    

// Menu option: overall multi-key sort for aliens
void overallSortAlien();    

// Displays the main menu and handles user interaction
void MainMenu();            


// ============================================================
// MAIN
// ============================================================
int main()
{
    // Display a title banner to the user
    cout << "=== Interplanetary Alliance Recruitment System ===\n\n";

    try
    {
        uploadingFiles();   // Load data from input files into global vectors
        MainMenu();         // Start the main menu loop for user interaction
    }
    catch (const runtime_error& e)    // Catch any runtime_error thrown in the program
    {
        cerr << "Runtime error: " << e.what() << endl;  // Print the error message
        return 1;                                       // Return non-zero to indicate failure
    }

    return 0;                  // Normal program termination
}


// ============================================================
// Function: uploadingFiles
//
// Loads human-crew.txt and alien-crew.txt,
// creates objects, and stores them in global vectors.
// ============================================================
void uploadingFiles()
{
    ifstream humanFile("human-crew.txt");   // Open the human crew data file
    ifstream alienFile("alien-crew.txt");   // Open the alien crew data file

    // Check if both files opened successfully
    if (!humanFile.is_open() || !alienFile.is_open())
    {
        cout << "Error opening one of the files.\n";   // Notify user of failure
        throw runtime_error("File open error");        // Throw an exception to be caught in main
    }
    else
    {
        cout << "Files opened successfully.\n";        // Confirm successful file opening
    }

    // Temporary variables used for reading from files
    string fName, lName;       // First name and last name
    string hSector;            // Sector for humans
    string hWorld;             // Homeworld for aliens
    float tScore;              // Training score
    int mAptitude;             // Mission aptitude

    // Telepathic-related attributes for aliens
    int sStrength;             // Signal Strength
    int cLink;                 // Cognitive Link
    int eOverlay;              // Empathic Overlay
    int cResistance;           // Cognitive Resistance
    int totalRanking;          // Precomputed Telepathic total ranking

    // Skip header line in human file (first line contains column names)
    getline(humanFile, fName);

    // Skip header line in alien file (first line contains column names)
    getline(alienFile, fName);

    // -----------------------------
    // Load Human crew data
    // -----------------------------
    // Read until we reach the end of the human file
    while (humanFile >> fName >> lName >> hSector >> tScore >> mAptitude)
    {
        // Construct a human object with the data from the current line
        human h(fName, lName, hSector, tScore, mAptitude);

        // Append the human object to the humanCrew vector
        humanCrew.push_back(h);
    }

    // -----------------------------
    // Load Alien crew data
    // -----------------------------
    // Read until we reach the end of the alien file
    while (alienFile >> fName >> lName >> hWorld >> tScore >> mAptitude
                     >> sStrength >> cLink >> eOverlay >> cResistance >> totalRanking)
    {
        // Construct an alien object with the data from the current line
        alien a(fName, lName, hWorld, tScore, mAptitude,
                sStrength, cLink, eOverlay, cResistance, totalRanking);

        // Append the alien object to the alienCrew vector
        alienCrew.push_back(a);
    }

    humanFile.close();     // Close the human file after reading
    alienFile.close();     // Close the alien file after reading

    // Display how many crew members were loaded from each file
    cout << "Number of Human Crew Members: " << humanCrew.size() << endl;
    cout << "Number of Alien Crew Members: " << alienCrew.size() << endl;
}


// ============================================================
// Function: singleFieldSortHuman
//
// Allows the user to sort humans by any one chosen field.
// Calls sorting functions from crew_sort.cpp.
// ============================================================
void singleFieldSortHuman()
{
    int choice;     // Stores the user's menu choice for sorting field

    // Print menu header and available options
    cout << "\n--- Single-Field Sort: HUMAN ---\n";
    cout << "1. Sort by Training Score (high to low)\n";
    cout << "2. Sort by Mission Aptitude (high to low)\n";
    cout << "3. Sort by First Name (A-Z)\n";
    cout << "4. Sort by Last Name (A-Z)\n";
    cout << "Enter choice: ";
    cin >> choice;  // Read the user's choice

    // Decide which sorting strategy to use
    switch (choice)
    {
    case 1: // Sort by training score
        sortedHumans = sortHumanTraining(humanCrew);   // Call sorting helper
        cout << "\nHumans sorted by Training Score:\n";
        for (const auto& h : sortedHumans)             // Loop through sorted results
            cout << h.getFirstName() << " " << h.getLastName()
                 << " - Score: " << h.getTrainingScore() << '\n';
        break;

    case 2: // Sort by mission aptitude
        sortedHumans = sortHumanAptitude(humanCrew);   // Call sorting helper
        cout << "\nHumans sorted by Mission Aptitude:\n";
        for (const auto& h : sortedHumans)             // Loop through sorted results
            cout << h.getFirstName() << " " << h.getLastName()
                 << " - Aptitude: " << h.getMissionAptitude() << '\n';
        break;

    case 3: // Sort by first name alphabetically
        sortedHumans = sortHumanFirstName(humanCrew);  // Call sorting helper
        cout << "\nHumans sorted by First Name:\n";
        for (const auto& h : sortedHumans)             // Loop through sorted results
            cout << h.getFirstName() << " " << h.getLastName() << '\n';
        break;

    case 4: // Sort by last name alphabetically
        sortedHumans = sortHumanLastName(humanCrew);   // Call sorting helper
        cout << "\nHumans sorted by Last Name:\n";
        for (const auto& h : sortedHumans)             // Loop through sorted results
            cout << h.getFirstName() << " " << h.getLastName() << '\n';
        break;

    default:    // If the user enters an invalid option
        cout << "Invalid choice\n";   // Notify user
        return;                       // Exit the function early
    }
}


// ============================================================
// Function: singleFieldSortAlien
//
// Allows the user to sort aliens by a single chosen field.
// ============================================================
void singleFieldSortAlien()
{
    int choice;     // Stores the user's menu choice for sorting field

    // Print menu header and available options
    cout << "\n--- Single-Field Sort: ALIEN ---\n";
    cout << "1. Sort by Training Score (high to low)\n";
    cout << "2. Sort by Mission Aptitude (high to low)\n";
    cout << "3. Sort by First Name (A-Z)\n";
    cout << "4. Sort by Last Name (A-Z)\n";
    cout << "Enter choice: ";
    cin >> choice;  // Read the user's choice

    // Decide which sorting strategy to use
    switch (choice)
    {
    case 1: // Sort aliens by training score
        sortedAliens = sortAlienTraining(alienCrew);   // Call sorting helper
        cout << "\nAliens sorted by Training Score:\n";
        for (const auto& a : sortedAliens)             // Loop through sorted results
            cout << a.getFirstName() << " " << a.getLastName()
                 << " - Score: " << a.getTrainingScore() << '\n';
        break;

    case 2: // Sort aliens by mission aptitude
        sortedAliens = sortAlienAptitude(alienCrew);   // Call sorting helper
        cout << "\nAliens sorted by Mission Aptitude:\n";
        for (const auto& a : sortedAliens)             // Loop through sorted results
            cout << a.getFirstName() << " " << a.getLastName()
                 << " - Aptitude: " << a.getMissionAptitude() << '\n';
        break;

    case 3: // Sort aliens by first name alphabetically
        sortedAliens = sortAlienFirstName(alienCrew);  // Call sorting helper
        cout << "\nAliens sorted by First Name:\n";
        for (const auto& a : sortedAliens)             // Loop through sorted results
            cout << a.getFirstName() << " " << a.getLastName() << '\n';
        break;

    case 4: // Sort aliens by last name alphabetically
        sortedAliens = sortAlienLastName(alienCrew);   // Call sorting helper
        cout << "\nAliens sorted by Last Name:\n";
        for (const auto& a : sortedAliens)             // Loop through sorted results
            cout << a.getFirstName() << " " << a.getLastName() << '\n';
        break;

    default:    // If the user enters an invalid option
        cout << "Invalid choice\n";   // Notify user
        return;                       // Exit the function early
    }
}


// ============================================================
// Function: overallSortHuman
//
// Sorts Humans using a *multi-key* comparison:
//   1. Mission Aptitude (primary)
//   2. Training Score (secondary)
//   3. Homeworld (tertiary)
// ============================================================
void overallSortHuman()
{
    // Explain to the user how the overall sorting is performed
    cout << "\n--- Overall Sort: HUMAN ---\n";
    cout << "Sorting by: Mission Aptitude (primary), Training Score (secondary), Homeworld (tertiary)\n";

    // Call the helper function that performs the multi-key sort
    sortedHumans = sortHumanOverall(humanCrew);

    // Display the final sorted order (names only)
    cout << "\nHumans sorted by Overall Ranking:\n";
    for (const auto& h : sortedHumans)
        cout << h.getFirstName() << " " << h.getLastName() << '\n';
}


// ============================================================
// Function: overallSortAlien
//
// Sorts Aliens using multi-key comparison:
//   1. Mission Aptitude
//   2. Training Score
//   3. Homeworld
//
// Also EXCLUDES any alien whose Telepathic Link Test total < 15.
// ============================================================
void overallSortAlien()
{
    // Explain to the user how the overall sorting is performed
    cout << "\n--- Overall Sort: ALIEN ---\n";
    cout << "Sorting by: Mission Aptitude (primary), Training Score (secondary), Homeworld (tertiary)\n";
    cout << "Note: Excludes aliens with Telepathic Link Test total < 15\n";

    // Call helper that sorts aliens and filters out low telepathic scores
    sortedAliens = sortAlienOverall(alienCrew);

    // Display the final sorted alien order (names only)
    cout << "\nAliens sorted by Overall Ranking (Telepathic >= 15):\n";
    for (const auto& a : sortedAliens)
        cout << a.getFirstName() << " " << a.getLastName() << '\n';
}


// ============================================================
// Function: MainMenu
//
// Displays main user menu and handles user actions.
// Repeats until the user chooses to exit (choice == 0).
// ============================================================
void MainMenu()
{
    int choice;    // Stores the main menu selection

    do
    {
        // Display the main menu UI
        cout << "\n========================================\n";
        cout << "   INTERPLANETARY ALLIANCE RECRUITMENT\n";
        cout << "========================================\n";
        cout << "1. Single-field sort (Human)\n";
        cout << "2. Single-field sort (Alien)\n";
        cout << "3. Overall sort (Human)\n";
        cout << "4. Overall sort (Alien)\n";
        cout << "5. Reload data files\n";
        cout << "0. Exit\n";
        cout << "========================================\n";
        cout << "Enter choice: ";
        cin >> choice;    // Read user's main menu choice

        // Perform action based on user's choice
        switch (choice)
        {
        case 1:                     // Choose single-field sort for humans
            singleFieldSortHuman(); // Call helper function
            break;
        case 2:                     // Choose single-field sort for aliens
            singleFieldSortAlien(); // Call helper function
            break;
        case 3:                     // Choose overall multi-key sort for humans
            overallSortHuman();     // Call helper function
            break;
        case 4:                     // Choose overall multi-key sort for aliens
            overallSortAlien();     // Call helper function
            break;
        case 5:                     // Reload crew data from files
            humanCrew.clear();      // Remove existing human data
            alienCrew.clear();      // Remove existing alien data
            uploadingFiles();       // Load fresh data again
            break;
        case 0:                     // Exit option
            cout << "\nThank you for using the Recruitment System!\n";
            break;
        default:                    // Any other input is invalid
            cout << "Invalid choice! Please try again!\n";
        }

    } while (choice != 0);          // Repeat menu until user chooses to exit
}
