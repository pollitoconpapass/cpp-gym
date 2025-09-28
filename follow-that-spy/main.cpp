/*
You've been provided with an array of itinerary routes, decipher the precise destinations he will visit in the correct sequence according to his meticulously planned itineraries.

Example
Based on the provided routes:
[ [USA, BRA], [JPN, PHL], [BRA, UAE], [UAE, JPN] ]

The correct sequence of destinations is:
"USA, BRA, UAE, JPN, PHL"

Note:
- You can safely assume that there will be no duplicate locations with distinct routes.
- All routes provided will have non-empty itineraries.
- There will always be at least one (1) route connecting one waypoint to another.

LINK: https://www.codewars.com/kata/5899a4b1a6648906fe000113/cpp
*/
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
using namespace std;

string getOriginDestination(const vector<pair<string,string>> &routes) {
    unordered_set<string> firsts, seconds;
    string originDestination;

    for (auto &p : routes) {
        firsts.insert(p.first);
        seconds.insert(p.second);
    }

    for (auto &city : firsts) {
        if (seconds.find(city) == seconds.end()) {
            originDestination = city;
        }
    }
    return originDestination;
}

string getSecondPairValue(vector<pair<string, string>> routes, string firstValue) {
    string result = "";
    for (auto &p : routes) {
        if (p.first == firstValue) {
            result = p.second;
            break;
        }
    }
    return result;
}

string find_routes(const vector<pair<string,string>> &routes) {
    string origin = getOriginDestination(routes) ; // -> first value
    string result = origin + ", ";

    string place2Look = origin;
    for (int i = 0; i < routes.size(); i++) {
        if (i == routes.size() - 1) {
            result += getSecondPairValue(routes, place2Look);
            place2Look = getSecondPairValue(routes, place2Look);
        }
        else {
            result += getSecondPairValue(routes, place2Look) + ", ";
            place2Look = getSecondPairValue(routes, place2Look);
        }
    }

    return result;
}

int main() {
    vector<pair<string, string>> routes = {{"MNL", "TAG"}, {"CEB", "TAC"}, {"TAG", "CEB"}, {"TAC", "BOR"}};
    cout << find_routes(routes) << endl;

    return 0;
}