#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_set>
using namespace std;


vector<int> initializeUniqueVector(int size, int minValue, int maxValue) {
    if (maxValue - minValue + 1 < size) {
        throw invalid_argument("The range is too small for the specified vector size.");
    }

    unordered_set<int> uniqueValues;
    vector<int> result;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minValue, maxValue);

    while (result.size() < size) {
        int value = dist(gen);
        if (uniqueValues.insert(value).second) {
            result.push_back(value);
        }
    }

    return result;
}


void swapExtremes(vector<int>& vec) {
    if (vec.empty()) return;

    auto minIt = min_element(vec.begin(), vec.end());
    auto maxIt = max_element(vec.begin(), vec.end());

    if (minIt != maxIt) {
        swap(*minIt, *maxIt);
    }
}

int main() {
    try {
        int size = 10;
        int minValue = 1;
        int maxValue = 100;

      
        vector<int> vec = initializeUniqueVector(size, minValue, maxValue);

        cout << "Source vector: ";
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;

        
        swapExtremes(vec);

        cout << "Vector after exchange of extreme elements: ";
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
