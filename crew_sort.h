#include "human.h"     // Include the human class definition so we can use vector<human>
#include "alien.h"     // Include the alien class definition so we can use vector<alien>
#include <vector>      // Include the standard vector container

using std::vector;     // Bring std::vector into the global namespace (optional but tidy)



// ============================================================================
// Function Prototypes for Sorting Humans
// Each function takes a const reference to a vector of human objects
// and returns a NEW vector<human> that is sorted according to the rule.
// ============================================================================

// Sort humans by training score (likely high to low); implementation in crew_sort.cpp
vector<human> sortHumanTraining(const vector<human>& input);

// Sort humans by mission aptitude (likely high to low)
vector<human> sortHumanAptitude(const vector<human>& input);

// Sort humans by first name (A-Z)
vector<human> sortHumanFirstName(const vector<human>& input);

// Sort humans by last name (A-Z)
vector<human> sortHumanLastName(const vector<human>& input);



// ============================================================================
// Function Prototypes for Sorting Aliens
// Same idea as human sorting, but for alien objects.
// ============================================================================

// Sort aliens by training score (likely high to low)
vector<alien> sortAlienTraining(const vector<alien>& input);

// Sort aliens by mission aptitude (likely high to low)
vector<alien> sortAlienAptitude(const vector<alien>& input);

// Sort aliens by first name (A-Z)
vector<alien> sortAlienFirstName(const vector<alien>& input);

// Sort aliens by last name (A-Z)
vector<alien> sortAlienLastName(const vector<alien>& input);



// ============================================================================
// Overall Sort Functions
//
// These perform *multi-key* sorts:
//   For Humans and Aliens, typically:
//       1. Mission Aptitude (primary)
//       2. Training Score (secondary)
//       3. Homeworld / Sector, etc. (tertiary)
//
// For Aliens, your program also filters out those with Telepathic total < 15
// inside sortAlienOverall (as per main.cpp behavior).
// ============================================================================

// Returns a new vector of humans sorted by overall ranking
vector<human> sortHumanOverall(const vector<human>& input);

// Returns a new vector of aliens sorted by overall ranking
vector<alien> sortAlienOverall(const vector<alien>& input);



// ============================================================================
// Generic Merge Sort Template
//
// A reusable merge sort implementation that can sort a vector<T>
// using a custom comparator function or functor passed as 'comp'.
//
// T can be human, alien, or any other type,
// as long as 'comp(a, b)' returns true if 'a' should come before 'b'.
// ============================================================================

template<typename T, typename Comparator>
vector<T> mergeSort(const vector<T>& vec, Comparator comp);
// Only the declaration is here; the template DEFINITION should be in the header too
// (or inlined in this file) so the compiler can instantiate it when needed.
