
#pragma once
#include <iostream> 


using namespace std; 



class TelepathicLinkTest 
{
    private:

        // Subscores
        int signalStrength, cognitiveLink, empathicOveraly; 


        // Subscore 
        // Cognitive Resistance ranges from 0 - 10 
        int cognitiveResistance; 

        // Will add up all the sub scores 
        int totalRanking; 

    public: 

        // Default Constructor 
        TelepathicLinkTest();

        // Parameterized Constructor
        TelepathicLinkTest(int sStrength, int cLink, int eOverlay, int cResistance, int totalRanking); 

        // Destructor 
        //~TelepathicLinkTest();



}; 


