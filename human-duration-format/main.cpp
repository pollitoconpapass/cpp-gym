/*
Write a function which formats a duration, given as a number of seconds, in a human-friendly way.

The function must accept a non-negative integer. If it is zero, it just returns "now". Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.

It is much easier to understand with an example:

* For seconds = 62, your function should return 
    "1 minute and 2 seconds"
* For seconds = 3662, your function should return
    "1 hour, 1 minute and 2 seconds"

For the purpose of this challenge, a year is 365 days and a day is 24 hours.
Note that spaces are important.


LINK: https://www.codewars.com/kata/52742f58faf5485cae000b9a/cpp
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

string format_duration(int seconds) {
    if (seconds == 0) return "now";

    vector<pair<string, int>> units = { // -> seconds for each unit
        {"year", 365 * 24 * 60 * 60}, // -> 31536000
        {"day", 24 * 60 * 60}, // -> 86400
        {"hour", 60 * 60}, // -> 3600
        {"minute", 60},
        {"second", 1}
    };

    vector<string> parts;

    for (auto &unit : units) {
        int count = seconds / unit.second;
        if (count > 0) {
            seconds %= unit.second;
            string part = to_string(count) + " " + unit.first;
            if (count > 1) part += "s"; // -> just in case its plural
            parts.push_back(part);
        }
    }

    // Build the final result
    string result;
    for (size_t i = 0; i < parts.size(); i++) {
        if (i > 0) {
            if (i == parts.size() - 1)
                result += " and ";  // -> last element
            else
                result += ", ";
        }
        result += parts[i];
    }

    return result;
}

int main() {
    cout << format_duration(62);
    return 0;
}