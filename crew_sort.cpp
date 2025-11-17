#include "crew_sort.h"  
// Includes the declarations for sortHumanTraining, sortAlienOverall, etc.
// Also pulls in human.h, alien.h, and <vector> indirectly.



// ============================================================================
// Template: mergeSort
//
// Generic merge sort that works on any vector<T> using a Comparator.
// 'comp(a, b)' should return true if 'a' should come BEFORE 'b'.
// ============================================================================

template<typename T, typename Comparator>
vector<T> mergeSort(const vector<T>& vec, Comparator comp) {
    // Base case: if the vector has 0 or 1 elements, it's already sorted.
    if (vec.size() <= 1) {
        return vec;          // Return the vector as-is.
    }
    
    // Compute the midpoint index for splitting the vector into two halves.
    int mid = static_cast<int>(vec.size() / 2);
    
    // Create a 'left' half from [begin, begin + mid)
    vector<T> left(vec.begin(), vec.begin() + mid);
    // Create a 'right' half from [begin + mid, end)
    vector<T> right(vec.begin() + mid, vec.end());
    
    // Recursively sort the left half
    left = mergeSort(left, comp);
    // Recursively sort the right half
    right = mergeSort(right, comp);
    
    // Prepare a new vector to hold the merged, sorted result
    vector<T> merged;
    merged.reserve(vec.size());   // Reserve memory to avoid reallocations
    
    // Indices for walking through left and right vectors
    int i = 0;   // Index into 'left'
    int j = 0;   // Index into 'right'
    
    // Merge the two sorted halves by repeatedly taking the "smaller" element
    // according to the comparator 'comp'
    while (i < static_cast<int>(left.size()) && j < static_cast<int>(right.size())) {
        // If left[i] should come before right[j], push left[i]
        if (comp(left[i], right[j])) {
            merged.push_back(left[i]);
            i++;    // Move forward in the left half
        }
        else {
            // Otherwise, push right[j]
            merged.push_back(right[j]);
            j++;    // Move forward in the right half
        }
    }
    
    // If there are remaining elements in 'left', append them
    while (i < static_cast<int>(left.size())) {
        merged.push_back(left[i]);
        i++;
    }
    
    // If there are remaining elements in 'right', append them
    while (j < static_cast<int>(right.size())) {
        merged.push_back(right[j]);
        j++;
    }
    
    // Return the fully merged and sorted vector
    return merged;
}



// ============================================================================
// Sorting Humans — using friend comparison functions
// ============================================================================

// Sort humans by training score (high to low)
// Uses compareTrainingScores from crewMember (friend function).
vector<human> sortHumanTraining(const vector<human>& input) {
    return mergeSort(input, [](const human& a, const human& b) {
        // compareTrainingScores returns -1, 0, or 1
        // We want 'a' BEFORE 'b' when a has a HIGHER training score.
        return compareTrainingScores(a, b) > 0;
    });
}

// Sort humans by mission aptitude (high to low)
vector<human> sortHumanAptitude(const vector<human>& input) {
    return mergeSort(input, [](const human& a, const human& b) {
        // Put higher mission aptitude first
        return compareMissionAptitudes(a, b) > 0;
    });
}

// Sort humans by first name (A–Z, ascending)
vector<human> sortHumanFirstName(const vector<human>& input) {
    return mergeSort(input, [](const human& a, const human& b) {
        // For alphabetical order, we want a < b (lexicographically)
        return compareFirstNames(a, b) < 0;
    });
}

// Sort humans by last name (A–Z, ascending)
vector<human> sortHumanLastName(const vector<human>& input){
    return mergeSort(input, [](const human& a, const human& b) {
        // For alphabetical order, we want a < b (lexicographically)
        return compareLastNames(a, b) < 0;
    });
}



// ============================================================================
// Sorting Aliens — using the SAME friend comparison functions
// ============================================================================

// Sort aliens by training score (high to low)
vector<alien> sortAlienTraining(const vector<alien>& input){
    return mergeSort(input, [](const alien& a, const alien& b) {
        // Aliens also inherit trainingScore from crewMember
        return compareTrainingScores(a, b) > 0;
    });
}

// Sort aliens by mission aptitude (high to low)
vector<alien> sortAlienAptitude(const vector<alien>& input) {
    return mergeSort(input, [](const alien& a, const alien& b) {
        // Compare their missionAptitude scores
        return compareMissionAptitudes(a, b) > 0;
    });
}

// Sort aliens by first name (A–Z)
vector<alien> sortAlienFirstName(const vector<alien>& input) {
    return mergeSort(input, [](const alien& a, const alien& b) {
        // Compare firstName lexicographically
        return compareFirstNames(a, b) < 0;
    });
}

// Sort aliens by last name (A–Z)
vector<alien> sortAlienLastName(const vector<alien>& input) {
    return mergeSort(input, [](const alien& a, const alien& b) {
        // Compare lastName lexicographically
        return compareLastNames(a, b) < 0;
    });
}



// ============================================================================
// Overall Sort: Humans
//
// Rule:
//   1. Higher mission aptitude comes first
//   2. If equal aptitude, higher training score comes first
//   3. If both equal, sort by last name alphabetically (A–Z)
// ============================================================================

vector<human> sortHumanOverall(const vector<human>& input){
    return mergeSort(input, [](const human& a, const human& b) {
        // First key: mission aptitude (descending)
        if (compareMissionAptitudes(a, b) != 0) {
            return compareMissionAptitudes(a, b) > 0;
        }
        
        // Second key: training score (descending)
        if (compareTrainingScores(a, b) != 0) {
            return compareTrainingScores(a, b) > 0;
        }
        
        // Third key: last name (ascending)
        return compareLastNames(a, b) < 0;
    });
}



// ============================================================================
// Overall Sort: Aliens
//
// Additional rule for aliens:
//   - EXCLUDE any alien whose Telepathic Link Test total < 15
//
// For the remaining aliens:
//   1. Higher mission aptitude comes first
//   2. If equal, higher training score comes first
//   3. If equal, sort by homeworld alphabetically (A–Z)
// ============================================================================

vector<alien> sortAlienOverall(const vector<alien>& input) {
    vector<alien> filtered;    // Temporary vector to store eligible aliens
    
    // First pass: filter aliens based on Telepathic total
    for (const alien& a : input) {
        // Only keep aliens whose telepathic total is 15 or higher
        if (a.getTelepathicTotal() >= 15) {
            filtered.push_back(a);
        }
    }
    
    // Now perform overall sorting on the filtered list
    return mergeSort(filtered, [](const alien& a, const alien& b) {
        // Primary key: mission aptitude (descending)
        if (compareMissionAptitudes(a, b) != 0) {
            return compareMissionAptitudes(a, b) > 0;
        }
        
        // Secondary key: training score (descending)
        if (compareTrainingScores(a, b) != 0) {
            return compareTrainingScores(a, b) > 0;
        }
        
        // Tertiary key: home world (ascending lexicographic order)
        return a.getHomeWorld() < b.getHomeWorld();
    });
}


// Any equal cases will fall the order of what they were in the input vector,
// preserving their relative order (stable sort).


// end of crew_sort.cpp -> using merge sort 

/* 
THE FOLLOWING CODE IS A PROTOTYPE OF SELECTION SORT IMPLEMENTATION FOR REFERENCE ONLY.

//Human Sorting functions
void sortHumansByTrainingScore(vector<human>& crew) {

    for (int i = 0; i < crew.size() - 1; i++) {
        int maxIndex = i;

        //Find the recruit with highest training score
        for (int j = i + 1; j < crew.size(); j++) {
            if (compareTrainingScores(crew[j], crew[maxIndex]) > 0) {
                maxIndex = j;
            }
        }

        //Swap if we found someone with higher score
        if (maxIndex != i) {
            human temp = crew[i];
            crew[i] = crew[maxIndex];
            crew[maxIndex] = temp;
        }
    }

}

void sortHumansByMissionAptitude(vector<human>&crew) {

    for (int i = 0; i < crew.size() - 1; i++) {
        int maxIndex = i;

        //Find the recruit with highest mission score
        for (int j = i + 1; j < crew.size(); j++) {
            if (compareMissionAptitudes(crew[j], crew[maxIndex]) > 0) {
                maxIndex = j;
            }
        }

        //Swap if we found someone with higher score
        if (maxIndex != i) {
            human temp = crew[i];
            crew[i] = crew[maxIndex];
            crew[maxIndex] = temp;
        }
    }

}

void sortHumansByFirstName(vector<human>& crew) {

    for (int i = 0; i < crew.size() - 1; i++) {
        int maxIndex = i;

        //Find the recruit with the earliest first name
        for (int j = i + 1; j < crew.size(); j++) {
            if (compareFirstNames(crew[j], crew[maxIndex]) > 0) {
                maxIndex = j;
            }
        }

        //Swap if we found someone earlier alphabetically
        if (maxIndex != i) {
            human temp = crew[i];
            crew[i] = crew[maxIndex];
            crew[maxIndex] = temp;
        }
    }

}

void sortHumansByLastName(vector<human>& crew) {

    for (int i = 0; i < crew.size() - 1; i++) {
        int maxIndex = i;

        //Find the recruit with the earliest last name
        for (int j = i + 1; j < crew.size(); j++) {
            if (compareLastNames(crew[j], crew[maxIndex]) > 0) {
                maxIndex = j;
            }
        }

        //Swap if we found someone earlier alphabetically
        if (maxIndex != i) {
            human temp = crew[i];
            crew[i] = crew[maxIndex];
            crew[maxIndex] = temp;
        }
    }

}


//Alien sorting functions
void sortAliensByTrainingScore(vector<alien>& crew) {

    for (int i = 0; i < crew.size() - 1; i++) {
        int maxIndex = i;

        //Find the recruit with highest training score
        for (int j = i + 1; j < crew.size(); j++) {
            if (compareTrainingScores(crew[j], crew[maxIndex]) > 0) {
                maxIndex = j;
            }
        }

        //Swap if we found someone with higher score
        if (maxIndex != i) {
            alien temp = crew[i];
            crew[i] = crew[maxIndex];
            crew[maxIndex] = temp;
        }
    }

}

void sortAliensByMissionAptitude(vector<alien>& crew) {

    for (int i = 0; i < crew.size() - 1; i++) {
        int maxIndex = i;

        //Find the recruit with highest mission score
        for (int j = i + 1; j < crew.size(); j++) {
            if (compareMissionAptitudes(crew[j], crew[maxIndex]) > 0) {
                maxIndex = j;
            }
        }

        //Swap if we found someone with higher score
        if (maxIndex != i) {
            alien temp = crew[i];
            crew[i] = crew[maxIndex];
            crew[maxIndex] = temp;
        }
    }

}

void sortAliensByFirstName(vector<alien>& crew) {

    for (int i = 0; i < crew.size() - 1; i++) {
        int maxIndex = i;

        //Find the recruit with the earliest first name
        for (int j = i + 1; j < crew.size(); j++) {
            if (compareFirstNames(crew[j], crew[maxIndex]) > 0) {
                maxIndex = j;
            }
        }

        //Swap if we found someone earlier alphabetically
        if (maxIndex != i) {
            alien temp = crew[i];
            crew[i] = crew[maxIndex];
            crew[maxIndex] = temp;
        }
    }

}

void sortAliensByLastName(vector<alien>& crew) {

    for (int i = 0; i < crew.size() - 1; i++) {
        int maxIndex = i;

        //Find the recruit with the earliest last name
        for (int j = i + 1; j < crew.size(); j++) {
            if (compareLastNames(crew[j], crew[maxIndex]) > 0) {
                maxIndex = j;
            }
        }

        //Swap if we found someone earlier alphabetically
        if (maxIndex != i) {
            alien temp = crew[i];
            crew[i] = crew[maxIndex];
            crew[maxIndex] = temp;
        }
    }

}


//Overall sorting functions
//Human
void sortHumansOverall(vector<human>& crew) {

    for (int i = 0; i < crew.size() - 1; i++) {
        int bestIndex = i;

        for (int j = i + 1; j < crew.size(); j++) {
            //Compare fields

            //Primary
            int aptitudeCompare = compareMissionAptitudes(crew[j], crew[bestIndex]);
            if (aptitudeCompare > 0) {
                bestIndex = j;
                continue;
            }
            if (aptitudeCompare < 0) {
                continue;
            }
            
            //Secondary
            int trainingCompare = compareTrainingScores(crew[j], crew[bestIndex]);
            if (trainingCompare > 0) {
                bestIndex = j;
                continue;
            }
            if (trainingCompare < 0) {
                continue;
            }

            //Tertiary
            string sectorJ = crew[j].getHumanSector();
            string sectorBest = crew[bestIndex].getHumanSector();
            if (sectorJ < sectorBest) {
                bestIndex = j;
            }

        }

        //Swap
        if (bestIndex != i) {
            human temp = crew[i];
            crew[i] = crew[bestIndex];
            crew[bestIndex] = temp;
        }
    }
}


//Alien
void sortAliensOverall(vector<alien>& crew) {

    cout << "DEBUG: Starting with " << crew.size() << " aliens" << endl;//debug

    vector<alien> filteredCrew;
    for (int i = 0; i < crew.size(); i++) {
        if (crew[i].getTelepathicLinkTest().getTotal() >= 15) {
            filteredCrew.push_back(crew[i]);
        }
    }

    for (int i = 0; i < filteredCrew.size() - 1; i++) {
        int bestIndex = i;

        for (int j = i + 1; j < filteredCrew.size(); j++) {
            //Compare fields

            //Primary
            int aptitudeCompare = compareMissionAptitudes(filteredCrew[j], filteredCrew[bestIndex]);
            if (aptitudeCompare > 0) {
                bestIndex = j;
                continue;
            }
            if (aptitudeCompare < 0) {
                continue;
            }

            //Secondary
            int trainingCompare = compareTrainingScores(filteredCrew[j], filteredCrew[bestIndex]);
            if (trainingCompare > 0) {
                bestIndex = j;
                continue;
            }
            if (trainingCompare < 0) {
                continue;
            }

            //Tertiary
            string sectorJ = filteredCrew[j].getHomeWorld();
            string sectorBest = filteredCrew[bestIndex].getHomeWorld();
            if (sectorJ < sectorBest) {
                bestIndex = j;
            }

        }

        //Swap
        if (bestIndex != i) {
            alien temp = filteredCrew[i];
            filteredCrew[i] = filteredCrew[bestIndex];
            filteredCrew[bestIndex] = temp;
        }
    }

    cout << "DEBUG: After filtering, " << filteredCrew.size() << " aliens remain" << endl;//debug
    crew = filteredCrew;
}



*/