#include "alien.h"
// Includes the alien class header so we can implement its methods here.



// ============================================================================
// Constructors
// ============================================================================


// Default Constructor 
// Calls the crewMember default constructor and initializes alien-specific fields.
alien::alien() : crewMember()
{
    homeWorld = "";          // Set home world to empty string
}; 



// Parameterized Constructor
// Initializes both the base class (crewMember) and alien-specific fields.
//
// crewMember(...) initializes:
//     - firstName
//     - lastName
//     - trainingScore
//     - missionAptitude
//     - userID (set to empty string "")
//
// object(...) initializes the TelepathicLinkTest member using its subscores.
alien::alien(string fName,
             string lName,
             string hWorld,
             float tScore,
             int mAptitude,
             int signalStrength,
             int cognitiveLink,
             int empathicOverlay,
             int cognitiveResistance,
             int totalRanking)
    : crewMember(fName, lName, tScore, mAptitude, ""),
      object(signalStrength, cognitiveLink, empathicOverlay, cognitiveResistance, totalRanking)
{
    homeWorld = hWorld;          // Assign home world
    telepathicTotal = totalRanking;   // Store final telepathic score
}; 



// ============================================================================
// Destructor (not needed — no dynamic memory)
// ============================================================================

/*
alien::~alien()
{

}
*/



// ============================================================================
// Getter Functions
// ============================================================================

// Returns the alien's home world.
// Marked const because it does not modify the object.
string alien::getHomeWorld() const
{
    return homeWorld;
}


// Returns the telepathic total score.
// Uses the TelepathicLinkTest object to retrieve the computed total.
int alien::getTelepathicTotal() const
{
    int total = object.getTelepathicTotal();   // Get total from object
    return total;
}



// ============================================================================
// Overloaded Stream Operator <<
// Allows printing an alien using:  cout << alienObject;
// ============================================================================

ostream& operator<<(ostream& os, const alien& a)
{
    os << "Alien Crew Member Details:\n";
    os << "First Name: " << a.getFirstName() << "\n";
    os << "Last Name: " << a.getLastName() << "\n";
    os << "Training Score: " << a.getTrainingScore() << "\n";
    os << "Mission Aptitude: " << a.getMissionAptitude() << "\n";
    os << "User ID: " << a.getUserID() << "\n";
    os << "Home World: " << a.getHomeWorld() << "\n";
    return os;   // Return stream to allow chaining (<<)
}

