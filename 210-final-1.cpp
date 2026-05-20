// COMSC-210 | Final 1 | Gillian Rhett

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // Milestone 1
    map<string, int> airports;
    ifstream in_file;
    in_file.open("210-final-1-SP26.txt");
    if (!in_file) {
        cout << "Error: couldn't open file.";
        return 1;
    }
    string str_temp;
    while(in_file >> str_temp) {
        if (airports.count(str_temp) == 0)
            airports.insert({str_temp, 1});
        else
            airports[str_temp]++;
    }
    cout << "All airport traffic counts:" << endl;
    for (auto pair : airports)
        cout << pair.first << " " << pair.second << endl;

    // Milestone 2:
    int highest = 0;
    for (auto pair : airports)
        if (pair.second > highest)
            highest = pair.second;
    vector<string> busiest;
    for (auto pair : airports)
        if (pair.second == highest)
            busiest.push_back(pair.first);
    cout << "Busiest airport(s) with count " << highest << ": ";
    int i = 0;
    for (string airport : busiest) {
        cout << airport << " (" << highest << ")";
        if (i < busiest.size() - 1)
            cout << ", ";
        else
            cout << endl;
        ++i;
    }

// Milestone 3: Add a function that prints only airports whose traffic counts fall within a specified inclusive range [low, high].
//    Your driver program should build the map and call the function at least twice with different ranges, clearly showing which airports fall in each range. Do not code user input. 

// Milestone 4: Final polishing, and make sure your driver program exercises all the milestones of this assignment.
    return 0;
}