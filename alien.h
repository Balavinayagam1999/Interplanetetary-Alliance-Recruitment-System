#pragma once
// Ensures this header file is included only once during compilation.
// Prevents duplicate class definitions.

#include "crewMember.h"         
// Include the base class so alien can inherit from crewMember.

#include "TelepathicLinkTest.h"
// Include TelepathicLinkTest because alien contains a TelepathicLinkTest object.


// ============================================================================
// CLASS: alien
//
// Represents an alien crew member.
// Inherits all common attributes (name, training score, aptitude, etc.)
// from the crewMember base class.
//
// Adds alien-specific attributes:
//   - homeWorld
//   - telepathicTotal
//   - TelepathicLinkTest object (stores sub-scores)
// ============================================================================

class alien : public crewMember
{
private:

    string homeWorld;      
    // Name of the alien's planet/home world

    int telepathicTotal;   
    // Stores the total telepathic ranking score (0–40 range in your dataset)

    TelepathicLinkTest object;  
    // Composition: alien HAS a TelepathicLinkTest object
    // This stores the telepathic subscores



public:

    // ------------------------------------------------------------------------
    // Default Constructor
    // Creates an "empty" alien with default values.
    // Implementation is in alien.cpp.
    // ------------------------------------------------------------------------
    alien();



    // ------------------------------------------------------------------------
    // Parameterized Constructor
    //
    // Used when reading alien data from alien-crew.txt.
    // Initializes:
    //   - Base class crewMember (via constructor inside alien.cpp)
    //   - homeWorld
    //   - telepathic subscores (via TelepathicLinkTest object)
    // ------------------------------------------------------------------------
    alien(string fName,
          string lName,
          string hWorld,
          float tScore,
          int mAptitude,
          int signalStrength,
          int cognitiveLink,
          int empathicOverlay,
          int cognitiveResistance,
          int totalRanking);



    // ------------------------------------------------------------------------
    // Destructor
    // Not needed (no dynamic memory), so it is commented out.
    // ------------------------------------------------------------------------
    // ~alien();



    // ------------------------------------------------------------------------
    // Getter: getHomeWorld
    // Returns the string representing the alien's planet.
    // const → guarantees no modification of the object.
    // ------------------------------------------------------------------------
    string getHomeWorld() const;



    // ------------------------------------------------------------------------
    // Getter: getTelepathicTotal
    // Returns the telepathic total score for sorting/filtering.
    // const → does not modify object.
    // ------------------------------------------------------------------------
    int getTelepathicTotal() const;



    // ------------------------------------------------------------------------
    // Overloaded Output Stream Operator <<
    //
    // Allows printing alien details using:
    //     cout << alienObject;
    //
    // Declared as a friend so the function can access private members.
    // Implemented in alien.cpp.
    // ------------------------------------------------------------------------
    friend ostream& operator<<(ostream& os, const alien& h);

};  // End of class alien

