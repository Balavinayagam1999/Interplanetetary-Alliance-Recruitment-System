#include "alien.h"



// Constructors ---------------------------------------------------------------------------
// Default Constructor 
alien::alien() : crewMember()
{
     homeWorld = ""; 
}; 

// Constructor that will take in parameters for crewMember and alien
alien::alien(string fName, string lName, string hWorld, float tScore, int mAptitude, int signalStrength, int cognitiveLink, int empathicOverlay, int cognitiveResistance, int totalRanking) 
            : crewMember(fName, lName, tScore, mAptitude, ""), object(signalStrength, cognitiveLink, empathicOverlay, cognitiveResistance, totalRanking)    
{
   
    homeWorld = hWorld;
}; 


/*
// Destructor
alien::~alien()
{

}
*/

//------------------------------------------------------------------------------------------


// Getter functions --------------------------------------------------------------------------

string alien::getHomeWorld() const
{
    return homeWorld; 
}


//------------------------------------------------------------------------------------------
;


// Overloaded stream operator << for alien class
ostream& operator<<(ostream& os, const alien& a)
{
    os << "Alien Crew Member Details:\n";
    os << "First Name: " << a.getFirstName() << "\n";
    os << "Last Name: " << a.getLastName() << "\n";
    os << "Training Score: " << a.getTrainingScore() << "\n";
    os << "Mission Aptitude: " << a.getMissionAptitude() << "\n";
    os << "User ID: " << a.getUserID() << "\n";
    os << "Home World: " << a.getHomeWorld() << "\n";
    return os;
}