#include "crewMember.h"   
// Includes the header file that contains the class declaration for crewMember.
// Required so the compiler knows the structure and member functions of the class.


// ============================================================================
// Constructors
// ============================================================================


// Default Constructor
// Initializes all crewMember fields to safe default values.
// No arguments are provided when this constructor is used.
crewMember::crewMember()
{
    firstName = "";          // Set first name to empty string
    lastName = "";           // Set last name to empty string
    trainingScore = 0.0;     // Set training score to zero
    missionAptitude = 0;     // Set mission aptitude to zero
    userID = "";             // Set user ID to empty string
}                            // End of default constructor



// Parameterized Constructor
// Creates a crewMember using meaningful values passed in as arguments.
// This version is called when all attributes are supplied.
crewMember::crewMember(string fName, string lName, float tScore,
                       int mAptitude, string uID)
{
    firstName = fName;          // Store the given first name
    lastName = lName;           // Store the given last name
    trainingScore = tScore;     // Store the given training score
    missionAptitude = mAptitude;// Store the given mission aptitude
    userID = uID;               // Store the given user ID
}                               // End of parameterized constructor



// ---------------------------------------------------------------------------
// Destructor (NOT needed)
// The class does not allocate memory dynamically (no new/delete),
// therefore a custom destructor is unnecessary.
// The default compiler-generated destructor is sufficient.
// ---------------------------------------------------------------------------

/*
crewMember::~crewMember()
{
    // No resources to free, so this stays empty.
}
*/



// ============================================================================
// Getter Functions (Accessors)
// These functions provide read-only access to private data members.
// Marked as const because they do NOT modify the object.
// ============================================================================


// Returns the crew member's first name
string crewMember::getFirstName() const
{
    return firstName;
}

// Returns the crew member's last name
string crewMember::getLastName() const
{
    return lastName;
}

// Returns the crew member's training score
float crewMember::getTrainingScore() const
{
    return trainingScore;
}

// Returns the crew member's mission aptitude score
int crewMember::getMissionAptitude() const
{
    return missionAptitude;
}

// Returns the crew member's user ID string
string crewMember::getUserID() const
{
    return userID;
}



// ============================================================================
// Friend Comparison Functions
// These helper functions compare two crewMember objects based on
// specific attributes.
// They return:
//    -1 if cm1 < cm2
//     1 if cm1 > cm2
//     0 if they are equal
// These are used by sorting functions in crew_sort.cpp
// ============================================================================


// Compare two crew members by training score (float)
int compareTrainingScores(const crewMember& cm1, const crewMember& cm2)
{
    if (cm1.trainingScore < cm2.trainingScore)
        return -1;
    else if (cm1.trainingScore > cm2.trainingScore)
        return 1;
    else
        return 0;
}


// Compare two crew members by mission aptitude (int)
int compareMissionAptitudes(const crewMember& cm1, const crewMember& cm2)
{
    if (cm1.missionAptitude < cm2.missionAptitude)
        return -1;
    else if (cm1.missionAptitude > cm2.missionAptitude)
        return 1;
    else
        return 0;
}


// Compare by first name (string comparison using < and >)
int compareFirstNames(const crewMember& cm1, const crewMember& cm2)
{
    if (cm1.firstName < cm2.firstName)
        return -1;
    else if (cm1.firstName > cm2.firstName)
        return 1;
    else
        return 0;
}


// Compare by last name (string comparison alphabetically)
int compareLastNames(const crewMember& cm1, const crewMember& cm2)
{
    if (cm1.lastName < cm2.lastName)
        return -1;
    else if (cm1.lastName > cm2.lastName)
        return 1;
    else
        return 0;
}
