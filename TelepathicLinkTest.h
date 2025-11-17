#pragma once
// Ensures this header file is included only once during compilation.
// Prevents redefinition errors (similar to #ifndef / #define guards).

#include <iostream>  
// Included for general use (string, streams, etc.). 
// Not strictly required here, but harmless and commonly included.

using namespace std;  
// Allows use of string, cout, etc. without the std:: prefix.



// ============================================================================
// CLASS: TelepathicLinkTest
//
// Represents the telepathic diagnostic profile for an alien.
// Stores several subscores and computes a total ranking.
// ============================================================================

class TelepathicLinkTest
{
private:

    // ------------------------------------------------------------------------
    // Subscore Components
    //
    // These represent telepathic-related ability metrics.
    // Stored as integers for simple arithmetic and comparisons.
    // ------------------------------------------------------------------------

    int signalStrength;      // Measures how strong the telepathic outgoing signal is
    int cognitiveLink;       // Measures how well an alien can connect to another mind
    int empathicOveraly;     // Measures emotional awareness overlap (typo kept as in your code)

    // Cognitive Resistance
    // Ranges from 0 to 10
    // Higher values mean stronger defense against telepathic intrusion
    int cognitiveResistance;

    // Total Telepathic Score
    // This is computed externally and passed into the constructor.
    // Represents a combined ranking of all subscores.
    int totalRanking;



public:

    // ------------------------------------------------------------------------
    // Default Constructor
    //
    // Initializes all telepathic subscores to zero.
    // Allows creation of an 'empty' or placeholder TelepathicLinkTest object.
    // ------------------------------------------------------------------------
    TelepathicLinkTest();



    // ------------------------------------------------------------------------
    // Parameterized Constructor
    //
    // Initializes all four subscores AND the total ranking score.
    // This is the constructor used when reading alien data from the file.
    // 
    // Parameters:
    //  sStrength     → signal strength subscore
    //  cLink         → cognitive link subscore
    //  eOverlay      → empathic overlay subscore
    //  cResistance   → cognitive resistance score
    //  totalRanking  → combined telepathic score
    // ------------------------------------------------------------------------
    TelepathicLinkTest(int sStrength,
                       int cLink,
                       int eOverlay,
                       int cResistance,
                       int totalRanking);



    // ------------------------------------------------------------------------
    // Destructor (not needed)
    //
    // Class contains no dynamic memory (no new/delete),
    // so the compiler-generated destructor is sufficient.
    // ------------------------------------------------------------------------
    // ~TelepathicLinkTest();



    // ------------------------------------------------------------------------
    // Getter: getTelepathicTotal
    //
    // Returns the overall telepathic score.
    // Marked const because it does NOT modify any member variables.
    // Used in filtering (e.g., in overallSortAlien).
    // ------------------------------------------------------------------------
    int getTelepathicTotal() const;

};   // End of class TelepathicLinkTest
