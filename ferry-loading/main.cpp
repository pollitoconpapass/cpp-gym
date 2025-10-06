/*
Before bridges were common, ferries were used to transport cars across rivers. 
River ferries, unlike their larger cousins, run on a guide line and are powered by the river’s current. 
Cars drive onto the ferry from one end, the ferry crosses the river, and the cars exit from the other end of the ferry.

There is a length-meter-long ferry that crosses the river. A car may arrive at either river bank to be transported by the ferry to the opposite bank. 
The ferry travels continuously back and forth between the banks so long as it is carrying a car or there is at least one car waiting at either bank. 
Whenever the ferry arrives at one of the banks, it unloads its cargo and loads up cars that are waiting to cross as long as they fit on its deck. 
The cars are loaded in the order of their arrival; ferry’s deck accommodates only one lane of cars. 
The ferry is initially on the left bank where it broke and it took quite some time to fix it. 
In the meantime, lines of cars formed on both banks that await to cross the river.

Input
Each test case receives an integer length and a vector pairs of integers and strings loads. Each loadsi has the length of a car (in centimeters), and the bank at which the car arrives (‘left’ or ‘right’).

Output
Return the number of times the ferry has to cross the river in order to serve all waiting cars.

Example
ferryLoading(20, {{380, "left"},{720, "left"},{1340, "right"},{1040, "left"}}) == 3;
ferryLoading(15, {{380, "left"},{720, "left"},{1340, "left"},{1040, "left"}}) == 5;

LINK: https://www.codewars.com/kata/5b9a6d77d16ffeea92000102/cpp
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;


int ferryLoading(const int length, vector<pair<int, string>> loads) {
    int ferryLength = length * 100; // convert meters to cm
    int crossingCount = 0;

    queue<int> leftQueue, rightQueue; // store only the lengths

    // Separate cars by bank while maintaining arrival order
    for (const auto& car : loads) {
        if (car.second == "left") {
            leftQueue.push(car.first);
        } else {
            rightQueue.push(car.first);
        }
    }

    string currentBank = "left";

    while (!leftQueue.empty() || !rightQueue.empty()) {
        int currentLoad = 0;

        // Load cars from the current bank
        if (currentBank == "left") {
            queue<int> temp;
            while (!leftQueue.empty()) {
                int carLength = leftQueue.front();
                if (currentLoad + carLength <= ferryLength) {
                    currentLoad += carLength;
                    leftQueue.pop();
                } else {
                    break; // Can't load more cars as this one doesn't fit
                }
            }
        } else { // currentBank == "right"
            queue<int> temp;
            while (!rightQueue.empty()) {
                int carLength = rightQueue.front();
                if (currentLoad + carLength <= ferryLength) {
                    currentLoad += carLength;
                    rightQueue.pop();
                } else {
                    break; // Can't load more cars as this one doesn't fit
                }
            }
        }

        crossingCount++;
        // Switch banks after each trip
        currentBank = (currentBank == "left") ? "right" : "left";

        // If the other bank has cars waiting, we need to cross again
        // If both banks are empty, we're done
        if (leftQueue.empty() && rightQueue.empty()) {
            break;
        }
    }

    return crossingCount;
}

int main() {
    int len = 20;
    vector<pair<int, string>> loads = {{380, "left"},{720, "left"},{1340, "right"},{1040, "left"}};
    cout << ferryLoading(len, loads) << endl;

    return 0;
}