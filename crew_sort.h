#include "human.h"
#include "alien.h"
#include <vector>

vector<human> sortHumanTraining(const vector<human>& input);
vector<human> sortHumanAptitude(const vector<human>& input);
vector<human> sortHumanFirstName(const vector<human>& input);
vector<human> sortHumanLastName(const vector<human>& input);

vector<alien> sortAlienTraining(const vector<alien>& input);
vector<alien> sortAlienAptitude(const vector<alien>& input);
vector<alien> sortAlienFirstName(const vector<alien>& input);
vector<alien> sortAlienLastName(const vector<alien>& input);

vector<human> sortHumanOverall(const vector<human>& input);
vector<alien> sortAlienOverall(const vector<alien>& input);

template<typename T, typename Comparator>
vector<T> mergeSort(const vector<T>& vec, Comparator comp);

