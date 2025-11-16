#pragma once
#include "crewMember.h"
#include "TelepathicLinkTest.h"



// Class Alien inherits from Class crewMember
class alien : public crewMember
{
    private: 
        string homeWorld; 
        TelepathicLinkTest object; // creating an object of TelepathicLinkTest class 
    public: 

        // Default Constructor 
        alien();

        // Constructor that will take in parameters for crewMember and alien
        alien(string fName, string lName, string hWorld, float tScore, int mAptitude, int signalStrength, int cognitiveLink, int empathicOverlay, int cognitiveResistance, int totalRanking); 

        // Destructor
        //~alien();
        string getHomeWorld() const;



        // stream operator << overload 
        friend ostream& operator<<(ostream& os, const alien& h);
};