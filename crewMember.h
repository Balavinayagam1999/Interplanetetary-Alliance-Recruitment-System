#pragma once
#include <iostream> 
#include <fstream> 

using namespace std; 

// g++ -std=c++17 -Wall main.cpp crewMember.cpp human.cpp alien.cpp TelepathicLinkTest.cpp -o crew.exe -> run this to create 
// Don't delete this comment above (Bala)


class crewMember
{
    private:
        string firstName, lastName; 
        float trainingScore; 
        int missionAptitude; 
        string userID; 
    public:
        // Default Constructor
        crewMember();

        // Parameterized Constructor
        crewMember(string fName, string lName, float tScore, int mAptitude, string uID); 
        
      
       
        // Destructor
        //~crewMember();

        // Getter function for first name
        string getFirstName() const; 

        // Getter function for last name
        string getLastName() const;  

        // Getter function for training score
        float getTrainingScore() const;

        // Getter function for mission aptitude
        int getMissionAptitude() const;

        // Getter function for user ID
        string getUserID() const;


        // Friend functions for comparisons
        // less than can be -1, 0 can be equal and greater than can be 1
        friend int compareTrainingScores(const crewMember& cm1, const crewMember& cm2);
        friend int compareMissionAptitudes(const crewMember& cm1, const crewMember& cm2);
        friend int compareFirstNames(const crewMember& cm1, const crewMember& cm2);
        friend int compareLastNames(const crewMember& cm1, const crewMember& cm2);


        
       


}; 


