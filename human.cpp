#include "human.h"


    
// Constructors ---------------------------------------------------------------------------   
    
// Default Constructor
human::human() : crewMember()
{
     humanSector = ""; 
};

// Constructor that will take in parameters for crewMember and human
human::human(string fName, string lName, string hSector, float tScore, int mAptitude) : crewMember(fName, lName, tScore, mAptitude, "")
{
    
    humanSector = hSector; 
} 

/*
// Destructor
human::~human()
{

};
*/
//------------------------------------------------------------------------------------------


// Getter functions --------------------------------------------------------------------------

string human::getHumanSector() const
{
    return humanSector; 
}

//------------------------------------------------------------------------------------------




// Overloaded stream operator << for human class
ostream& operator<<(ostream& os, const human& h)
{
    os << "Human Crew Member Details:\n";
    os << "First Name: " << h.getFirstName() << "\n";
    os << "Last Name: " << h.getLastName() << "\n";
    os << "Training Score: " << h.getTrainingScore() << "\n";
    os << "Mission Aptitude: " << h.getMissionAptitude() << "\n";
    os << "User ID: " << h.getUserID() << "\n";
    os << "Human Sector: " << h.getHumanSector() << "\n";
    return os;
}