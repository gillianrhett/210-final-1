// COMSC-210 | Final 1 | Gillian Rhett

#include <map>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
// Milestone 1: In this assignment's details page, download and install the text file as your data source for this project. In it, each line contains two airport codes representing a particular flight's origin and destination, for example:
// JFK LAX
// Create an std::map<std::string, int> that maps an airport code to its traffic count. Read the file, and for each flight, insert origin and destination airports into the map if they do not exist yet; and increment each airport’s count once.
//    Your driver program should build the map from the file and print all airports and their counts in the natural sorted order of the map. 
    
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

// Milestone 2: Add code that finds the highest traffic count to represent the busiest airport. Print all airports that have this maximum count (in other words, handle ties).
//     Your driver program should build the map, print all counts, and then print the busiest airport(s) and their count. 

// Milestone 3: Add a function that prints only airports whose traffic counts fall within a specified inclusive range [low, high].
//    Your driver program should build the map and call the function at least twice with different ranges, clearly showing which airports fall in each range. Do not code user input. 

// Milestone 4: Final polishing, and make sure your driver program exercises all the milestones of this assignment.
    return 0;
}