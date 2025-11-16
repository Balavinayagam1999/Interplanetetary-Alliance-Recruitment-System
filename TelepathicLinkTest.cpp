#include "TelepathicLinkTest.h"



// Constructors ---------------------------------------------------------------------------

// Default Constructor 
TelepathicLinkTest::TelepathicLinkTest() 
{
    signalStrength = 0; 
    cognitiveLink = 0; 
    empathicOveraly = 0; 
    cognitiveResistance = 0; 
    totalRanking = 0; 
}

// Parameterized Constructor
TelepathicLinkTest::TelepathicLinkTest(int sStrength, int cLink, int eOverlay, int cResistance, int totalRanking) 
{
    signalStrength = sStrength; // signal 
    cognitiveLink = cLink; // cognitive
    empathicOveraly = eOverlay; // empathic

    // cognitive resistance -> Need to check if its between 0-10. 
    if(cResistance < 0 || cResistance > 10) 
    {
        cognitiveResistance = 0; 
    }
    else
    {
        cognitiveResistance = cResistance; 
    }

    totalRanking = totalRanking; 
}

/*
 Destructor 
TelepathicLinkTest::~TelepathicLinkTest() 
{

}; 
*/ 

//------------------------------------------------------------------------------------------

