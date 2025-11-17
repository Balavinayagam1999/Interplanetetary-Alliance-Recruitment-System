#pragma once
// Ensures this header file is included only once during compilation.
// Prevents duplicate class definitions (acts like an include guard).

#include <iostream>    // Needed for std::string, std::ostream, etc.
#include <fstream>     // Included here (not strictly needed in this header)
// (Keeping it because you might expand this class later.)

using namespace std;   // Allows use of string, ostream, etc. without std:: prefix



// ============================================================================
// NOTE (from assignment instructions):
//   The comment below shows how to compile the full program. Leave it untouched.
// ============================================================================
/*
g++ -std=c++17 -Wall main.cpp crewMember.cpp human.cpp alien.cpp TelepathicLinkTest.cpp -o crew.exe
*/
// Don't delete this comment above (Bala)



// ============================================================================
// CLASS: crewMember
//
// Represents a general crew member. This is the BASE CLASS for:
//      - human
//      - alien
//
// It stores attributes common to both types of crew members.
// ============================================================================

class crewMember
{
private:
    // ------------------------------------------------------------------------
    // Private Data Members
    // These variables cannot be directly accessed outside the class.
    // Derived classes (like human or alien) also cannot access them directly.
    // Access is through public getters.
    // ------------------------------------------------------------------------
    string firstName;         // Crew member's first name
    string lastName;          // Crew member's last name
    float trainingScore;      // Float value: score from academy training
    int missionAptitude;      // Integer rating: aptitude for missions
    string userID;            // Unique ID assigned to each crew member



public:
    // ------------------------------------------------------------------------
    // Constructors
    // ------------------------------------------------------------------------

    // Default Constructor
    // Creates an "empty" crew member with default values.
    crewMember();

    // Parameterized Constructor
    // Creates a fully-initialized crew member with given values.
    crewMember(string fName,
               string lName,
               float tScore,
               int mAptitude,
               string uID);


    // ------------------------------------------------------------------------
    // Destructor (not needed)
    //
    // Since crewMember does NOT use dynamic memory (no new/delete),
    // the compiler-generated destructor is sufficient.
    // ------------------------------------------------------------------------
    // ~crewMember();



    // ------------------------------------------------------------------------
    // Getter Functions (Accessors)
    // These return internal values without modifying the object.
    // Marked "const" because they do not change member variables.
    // ------------------------------------------------------------------------

    // Returns the crew member’s first name
    string getFirstName() const;

    // Returns the crew member’s last name
    string getLastName() const;

    // Returns the crew member’s training score
    float getTrainingScore() const;

    // Returns the mission aptitude rating
    int getMissionAptitude() const;

    // Returns the user ID string
    string getUserID() const;



    // ------------------------------------------------------------------------
    // Friend Comparison Functions
    //
    // These allow sorting crewMember objects based on different attributes.
    // They return:
    //      -1  => cm1 < cm2
    //       0  => cm1 == cm2
    //       1  => cm1 > cm2
    //
    // These functions are declared "friend" so they can access private members
    // directly (like firstName, trainingScore, etc.)
    // ------------------------------------------------------------------------

    friend int compareTrainingScores(const crewMember& cm1,
                                     const crewMember& cm2);

    friend int compareMissionAptitudes(const crewMember& cm1,
                                       const crewMember& cm2);

    friend int compareFirstNames(const crewMember& cm1,
                                 const crewMember& cm2);

    friend int compareLastNames(const crewMember& cm1,
                                const crewMember& cm2);

};  // End of class crewMember

