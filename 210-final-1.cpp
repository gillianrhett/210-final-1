// COMSC-210 | Final 1 | Gillian Rhett

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// for Milestone 3
void display_in_range(int, int, const map<string, int>&);

int main() {

    // Milestone 1: store the airport codes and each airport's total traffic count in a map
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

    // Milestone 2: find the greatest traffic count and display all airports that have that much traffic
    int highest = 0;
    for (auto pair : airports)
        if (pair.second > highest)
            highest = pair.second;
    vector<string> busiest;
    for (auto pair : airports)
        if (pair.second == highest)
            busiest.push_back(pair.first);
    cout << "\nBusiest airport(s) with count " << highest << ": " << endl;
    int i = 0;
    for (string airport : busiest) {
        cout << airport << " (" << highest << ")";
        if (i < busiest.size() - 1)
            cout << ", ";
        else
            cout << endl;
        ++i;
    }
    cout << endl;

    // Milestone 3: display the airports that are within these ranges of traffic counts
    display_in_range(10, 20, airports);
    display_in_range(4, 12, airports);

    return 0;
}

// Milestone 3: display the airports and their traffic counts within the given range of traffic counts (inclusive)
void display_in_range(int low, int high, const map<string, int>& in_map) {
    cout << "Airports with traffic in range [" << low << ", " << high << "]: " << endl;
    for (auto pair : in_map)
        if (low <= pair.second && pair.second <= high)
            cout << pair.first << " " << pair.second << endl;
    cout << endl;
}