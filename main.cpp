#include <iostream> 
#include <fstream>
#include <vector>
#include "human.h"
#include "alien.h"


// g++ -std=c++17 -Wall main.cpp crewMember.cpp human.cpp alien.cpp TelepathicLinkTest.cpp -o crew.exe -> run this to create 
// Don't delete this comment above (Bala)

// Declare Global vectors to store human and alien crew members
vector<human> humanCrew;
vector<alien> alienCrew;

using namespace std;

void uploadingFiles(); 
//void sortingCrewMembers(sortOptions);

// Enum
enum sortOptions
{
    TRAINING_SCORE,
    MISSION_APTITUDE,
    FIRST_NAME,
    LAST_NAME
};

int main()
{
    
    try 
    {
        uploadingFiles();
    }
    catch (const runtime_error& e) 
    {
        cerr << "Runtime error: " << e.what() << endl;
        return 1; 
    }

    /*
    try z
    {
        sortingCrewMembers(TRAINING_SCORE);
    }
    catch (const runtime_error& e) 
    {
        cerr << "Runtime error: " << e.what() << endl;
        return 1; 
    }
    */
   
    return 0;
}


// This functilon will upload files and create objects of human and alien classes
void uploadingFiles()
{
    // Create input file stream objects
    ifstream humanFile("human-crew.txt");
    ifstream alienFile("alien-crew.txt");
    
     // Check if files are open
    if (!humanFile.is_open() || !alienFile.is_open()) 
    {
        cout << "Error opening one of the files." << endl;
        throw runtime_error("File open error");
    }
    else 
    {
        cout << "Files opened successfully." << endl;
    }

    // Variables to hold data read from files
    string fName, lName, uID, hSector, hWorld;
    float tScore;
    int mAptitude;

    int sStrength, cLink, eOverlay, cResistance, totalRanking;

    
    getline(humanFile, fName); // Read and discard header line from human crew file
    getline(alienFile, fName); // Discard header line from alien crew file

     // Read human crew data and create human objects 
    while (humanFile >> fName >> lName >> hSector >> tScore >> mAptitude)
    {
        human h(fName, lName, hSector, tScore, mAptitude);
        humanCrew.push_back(h);
    }

    // Read alien crew data
    while (alienFile >> fName >> lName >> hWorld >>  tScore >> mAptitude >> sStrength >> cLink >> eOverlay >> cResistance >> totalRanking)
    {
        alien a(fName, lName, hWorld, tScore, mAptitude, sStrength, cLink, eOverlay, cResistance, totalRanking);
        alienCrew.push_back(a);
    }

    // Close the files
    humanFile.close();
    alienFile.close();

    // Output the number of crew members read
    cout << "Number of Human Crew Members: " << humanCrew.size() << endl;
    cout << "Number of Alien Crew Members: " << alienCrew.size() << endl;

}

/*
void sortingCrewMembers(sortOptions options)
{

    // Need to fix this 
    int choice;
    cout << "Sorting crew members based on selected option..." << endl;
    cout << "1. Training Score" << endl;
    cout << "2. Mission Aptitude" << endl;
    cout << "3. First Name" << endl;
    cout << "4. Last Name" << endl;
    cin >> choice; 

    // Need to reduce choice by 1 to match enum indexing
    // enum indexing starts from 0-3 while choice goes from 1-4 (as we provided)
    options = static_cast<sortOptions>(choice - 1);

    // Sorting logic will be implemented here based on the selected option
    switch(options)
    {
        case TRAINING_SCORE:
            // Sort by training score
            break;
        case MISSION_APTITUDE:
            // Sort by mission aptitude
            break;
        case FIRST_NAME:
            // Sort by first name
            break;
        case LAST_NAME:
            // Sort by last name
            break;
        default:
            throw runtime_error("Invalid sorting option");
            break;
    }
};
*/ 