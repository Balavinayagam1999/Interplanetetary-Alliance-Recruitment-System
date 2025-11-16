#pragma once
#include "crewMember.h"



// Class human inherits from  public attributes of Class crewMember
class human : public crewMember
{
    private:
        string humanSector; 
    public:

        // Default Constructor
        human();  // only declaration

        human(string fName, string lName, string hSector,float tScore, int mAptitude);  // only declaration

        string getHumanSector() const;
        // Destructor
        
        
        //~human();


        // stream operator << overload 
        friend ostream& operator<<(ostream& os, const human& h);
        
};

