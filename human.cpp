#include "human.h"     // Include the header file for the human class



// ============================================================================
// Constructors
// ============================================================================

// Default Constructor
// Calls the base class (crewMember) default constructor
// Initializes humanSector to an empty string
human::human() : crewMember()
{
    humanSector = "";      // Set humanSector to an empty string
}


// Constructor with parameters
// Initializes the base class crewMember with first name, last name,
// training score, mission aptitude, and **empty user ID**
// Then sets the derived human-specific field humanSector
human::human(string fName, string lName, string hSector,
             float tScore, int mAptitude)
    : crewMember(fName, lName, tScore, mAptitude, "")  // Call base class constructor
{
    humanSector = hSector;   // Set the human sector (unique to humans)
}


// ---------------------------------------------------------------------------
// Note: Destructor is commented out because it's not needed.
// The compiler automatically generates a correct destructor.
// ---------------------------------------------------------------------------

/*
human::~human()
{
    // No dynamic memory -> nothing special to clean up
};
*/


// ============================================================================
// Getter Function
// ============================================================================

// Returns the sector assigned to this human crew member.
// Marked as const because it does not modify the object.
string human::getHumanSector() const
{
    return humanSector;      // Provide stored sector string
}



// ============================================================================
// Overloaded Output Stream Operator (<<)
// Allows printing a human object using cout << h;
// ============================================================================

ostream& operator<<(ostream& os, const human& h)
{
    // Print all relevant human and inherited crewMember details
    os << "Human Crew Member Details:\n";
    os << "First Name: " << h.getFirstName() << "\n";
    os << "Last Name: " << h.getLastName() << "\n";
    os << "Training Score: " << h.getTrainingScore() << "\n";
    os << "Mission Aptitude: " << h.getMissionAptitude() << "\n";
    os << "User ID: " << h.getUserID() << "\n";
    os << "Human Sector: " << h.getHumanSector() << "\n";

    return os;    // Return ostream to allow chaining (e.g., cout << h << endl)
}
