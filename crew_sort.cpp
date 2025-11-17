#include "crew_sort.h"

template<typename T, typename Comparator>
vector<T> mergeSort(const vector<T>& vec, Comparator comp) {
    if (vec.size() <= 1) {
        return vec;
    }
    
    int mid = (vec.size() / 2);
    
    vector<T> left(vec.begin(), vec.begin() + mid);
    vector<T> right(vec.begin() + mid, vec.end());
    
    left = mergeSort(left, comp);
    right = mergeSort(right, comp);
    
    vector<T> merged;
    merged.reserve(vec.size());
    
    int i = 0, j = 0, k = 0;
    
    while (i < left.size() && j < right.size()) {
        if (comp(left[i], right[j])) {
            merged[k] = left[i];
            i++;
        }
        
        else {
            merged[k] = right[j];
            j++;
        }
        
        k++;
    }
    
    while (i < left.size()) {
        merged[k] = left[i];
        i++;
        k++;
    }
    
    while (j < right.size()) {
        merged[k] = right[j];
        j++;
        k++;
    }
    
    return merged;
}

vector<human> sortHumanTraining(const vector<human>& input) {
    return mergeSort(input, [](const human& a, const human& b) {
        return a.getTrainingScore() > b.getTrainingScore();
    });
}
vector<human> sortHumanAptitude(const vector<human>& input) {
    return mergeSort(input, [](const human& a, const human& b) {
        return a.getMissionAptitude() > b.getMissionAptitude();
    });
}
vector<human> sortHumanFirstName(const vector<human>& input) {
    return mergeSort(input, [](const human& a, const human& b) {
        return a.getFirstName() < b.getFirstName();
    });
}
vector<human> sortHumanLastName(const vector<human>& input){
    return mergeSort(input, [](const human& a, const human& b) {
        return a.getLastName() < b.getLastName();
    });
}


vector<alien> sortAlienTraining(const vector<alien>& input){
    return mergeSort(input, [](const alien& a, const alien& b) {
        return a.getTrainingScore() > b.getTrainingScore();
    });
}
vector<alien> sortAlienAptitude(const vector<alien>& input) {
    return mergeSort(input, [](const alien& a, const alien& b) {
        return a.getMissionAptitude() > b.getMissionAptitude();
    });
}
vector<alien> sortAlienFirstName(const vector<alien>& input) {
    return mergeSort(input, [](const alien& a, const alien& b) {
        return a.getFirstName() < b.getFirstName();
    });
}
vector<alien> sortAlienLastName(const vector<alien>& input) {
    return mergeSort(input, [](const alien& a, const alien& b) {
        return a.getLastName() < b.getLastName();
    });
}

vector<human> sortHumanOverall(const vector<human>& input){
    return mergeSort(input, [](const human& a, const human& b) {
        if (a.getMissionAptitude() != b.getMissionAptitude()) {
            return a.getMissionAptitude() > b.getMissionAptitude();
        }
        
        if (a.getTrainingScore() != b.getTrainingScore()) {
            return a.getTrainingScore() > b.getTrainingScore();
        }
        
        return a.getHumanSector() < b.getHumanSector();
    });
}

vector<alien> sortAlienOverall(const vector<alien>& input) {
    vector<alien> filtered;
    
    for (const alien& a : input) {
        if (a.getTelepathicTotal() >= 15) {
            filtered.push_back(a);
        }
    }
    
    return mergeSort(filtered, [](const alien& a, const alien& b) {
        if (a.getMissionAptitude() != b.getMissionAptitude()) {
            return a.getMissionAptitude() > b.getMissionAptitude();
        }
        
        if (a.getTrainingScore() != b.getTrainingScore()) {
            return a.getTrainingScore() > b.getTrainingScore();
        }
        
        return a.getHomeWorld() < b.getHomeWorld();
    });
}