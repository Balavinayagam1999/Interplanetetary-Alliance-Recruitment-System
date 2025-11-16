#include "crewMember.h"



// Constructors ---------------------------------------------------------------------------

// Default Constructor
crewMember::crewMember()   
{
    firstName = ""; 
    lastName = ""; 
    trainingScore = 0.0; 
    missionAptitude = 0; 
    userID = ""; 
}

// Parameterized Constructor
crewMember::crewMember(string fName, string lName, float tScore, int mAptitude, string uID)
{
    firstName = fName; // Initialize first name
    lastName = lName; // Initialize last name
    trainingScore = tScore; // Initialize training score
    missionAptitude = mAptitude; // Initialize mission aptitude
    userID = uID; // Initialize user ID
} 


/*
// Destructor
crewMember::~crewMember()
{

};
*/
//----------------------------------------------------------------------------------------------------------




// Getter functions --------------------------------------------------------------------------

// Getter for firstName
string crewMember::getFirstName() const
{
    return firstName; 
} 

// Getter for lastName
string crewMember::getLastName() const
{
    return lastName; 
} 

// Getter for trainingScore
float crewMember::getTrainingScore() const
{
    return trainingScore; 
} 

// Getter for missionAptitude
int crewMember::getMissionAptitude() const
{
    return missionAptitude; 
} 

// Getter for userID
string crewMember::getUserID() const
{
    return userID; 
}

//--------------------------------------------------------------------------------------------


// Friend functions for comparisons ----------------------------------------------------------
int compareTrainingScores(const crewMember& cm1, const crewMember& cm2)
{
    if(cm1.trainingScore < cm2.trainingScore)
        return -1; 
    else if(cm1.trainingScore > cm2.trainingScore)
        return 1; 
    else
        return 0; 
}

int compareMissionAptitudes(const crewMember& cm1, const crewMember& cm2)
{
    if(cm1.missionAptitude < cm2.missionAptitude)
        return -1; 
    else if(cm1.missionAptitude > cm2.missionAptitude)
        return 1; 
    else
        return 0; 
}

int compareFirstNames(const crewMember& cm1, const crewMember& cm2)
{
    if(cm1.firstName < cm2.firstName)
        return -1; 
    else if(cm1.firstName > cm2.firstName)
        return 1; 
    else
        return 0; 
}

int compareLastNames(const crewMember& cm1, const crewMember& cm2)
{
    if(cm1.lastName < cm2.lastName)
        return -1; 
    else if(cm1.lastName > cm2.lastName)
        return 1; 
    else
        return 0; 
}
//------------------------------------------------------------------------------------------
