#include "TelepathicLinkTest.h"
// Includes the header file so we can define the class methods here.



// ============================================================================
// Constructors
// ============================================================================


// Default Constructor 
// Initializes all telepathic subscores and the total ranking to zero.
TelepathicLinkTest::TelepathicLinkTest() 
{
    signalStrength = 0;        // Default: no telepathic signal strength
    cognitiveLink = 0;         // Default: no cognitive linking ability
    empathicOveraly = 0;       // Default: no empathic overlay detected
    cognitiveResistance = 0;   // Default: no resistance against telepathy
    totalRanking = 0;          // Default total score
}



// Parameterized Constructor
// Assigns provided values to each subscore.
TelepathicLinkTest::TelepathicLinkTest(int sStrength,
                                       int cLink,
                                       int eOverlay,
                                       int cResistance,
                                       int totalRanking) 
{
    signalStrength = sStrength;     // Set signal strength score
    cognitiveLink = cLink;          // Set cognitive link score
    empathicOveraly = eOverlay;     // Set empathic overlay score

    // Validate cognitive resistance value (must be between 0 and 10)
    if (cResistance < 0 || cResistance > 10) 
    {
        cognitiveResistance = 0;    // Invalid -> set to default
    }
    else
    {
        cognitiveResistance = cResistance;  // Valid -> assign
    }

    // Assign total ranking using "this->" to reference the member variable
    this->totalRanking = totalRanking;
}



// ============================================================================
// Destructor (commented out — not needed because no dynamic memory)
// ============================================================================

/*
Destructor 
TelepathicLinkTest::~TelepathicLinkTest() 
{

}; 
*/ 



// ============================================================================
// Getter Function
// ============================================================================

// Returns the total telepathic ranking score.
// Marked const because it does not modify the object state.
int TelepathicLinkTest::getTelepathicTotal() const
{
    return totalRanking;
}
