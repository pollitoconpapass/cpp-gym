/*
Given a list of friend pairs, find a clique of three (a.k.a. triangle): a group of three people who are all friends with each other.

For example, given the input:
Harry/Ron
Ron/Hermione
Harry/Hermione
Hermione/Lavender

... you should return: Harry/Ron/Hermione

The order of the three names in the returned string does not matter.
If there is no clique-of-three, return an empty string.

LINK: https://www.codewars.com/kata/5d2d115dc42a1300250b6f8d/cpp
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split_string(const string &s, char delimiter) {
    vector<std::string> tokens;
    string token;
    stringstream ss(s);

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string clique_of_3(const string &friends) { // -> mine
    unordered_map<string,vector<string>> friends_map;
    vector<string> friends_vec = split_string(friends, '\n');

    for (auto c : friends_vec) {
        vector<string> tokens = split_string(c, '/');
        friends_map[tokens[0]].push_back(tokens[1]);
    }

    string result = "";
    for (auto pair : friends_map) {
        if (pair.second.size() > 1) {
            result += pair.first + "/";
            for (int i = 0; i < pair.second.size(); i++) {
                result +=  pair.second[i] + "/";
            }
        }
    }

    return result.erase(result.size()- 1, 1);
}

string clique_of_3_v2(const string &friends) { // -> refactored by GPT :)
    unordered_map<string, unordered_set<string>> graph;
    vector<string> friends_vec = split_string(friends, '\n');

    for (auto &c : friends_vec) {
        vector<string> tokens = split_string(c, '/');
        if (tokens.size() != 2) continue;
        string a = tokens[0], b = tokens[1];
        if (a == b) continue; // ignore self-friendship
        graph[a].insert(b);
        graph[b].insert(a);
    }

    for (auto &entry : graph) {
        const string &person = entry.first;
        const auto &friends_set = entry.second;
        vector<string> friends_list(friends_set.begin(), friends_set.end());

        for (size_t i = 0; i < friends_list.size(); i++) {
            for (size_t j = i + 1; j < friends_list.size(); j++) {
                const string &f1 = friends_list[i];
                const string &f2 = friends_list[j];

                if (graph[f1].count(f2)) {
                    return person + "/" + f1 + "/" + f2;
                }
            }
        }
    }

    return "";
}

int main() {
    string input = "A/B\nB/C\nA/A\nA/F\nF/B\n";
        // "His Majesty The King/His Royal Highness the Prince of Wales\nHis Royal Highness the Prince of Wales/Her Royal Highness the Princess of Wales\nHis Majesty The King/Her Royal Highness the Princess of Wales";
        // "Harry/Ron\nRon/Hermione\nHarry/Hermione\nHermione/Lavender\n";
    cout << clique_of_3_v2(input) << endl;

    return 0;
}