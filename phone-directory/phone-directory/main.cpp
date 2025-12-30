/*
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. 
The task is to implement a search query for the phone directory. 
Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. 
Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".

Example 1:
Input: 
n = 3
contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explaination: By running the search query on 
contact list for "g" we get: "geeikistest", 
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list 
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0". 
No results found for "geeips", so print "0".


Your Task:
You do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and 
returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

LINK: https://www.geeksforgeeks.org/problems/phone-directory4628/1?page=1&category=Map&difficulty=Hard&sortBy=submissions
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> displayContacts(int n, vector<string>& contact, string s) {
        set<string> uniqueContacts(contact.begin(), contact.end());
        map<string, set<string>> prefixMap;
        for (const string& name : uniqueContacts) {
            string prefix = "";
            for (char ch : name) {
                prefix += ch;
                prefixMap[prefix].insert(name);
            }
        }
        vector<vector<string>> result;
        string searchPrefix = "";
        for (char ch : s) {
            searchPrefix += ch;
            if (prefixMap.find(searchPrefix) != prefixMap.end()) {
                vector<string> matches(prefixMap[searchPrefix].begin(), prefixMap[searchPrefix].end());
                result.push_back(matches);
            }
            else {
                result.push_back({ "0" });
            }
        }

        return result;
    }
};

int main() {
    int n;
    cout << "ingrese el numero de contactos: ";
    cin >> n;

    vector<string> contact(n);
    cout << "ingrese los contactos uno por uno:\n";
    for (int i = 0; i < n; i++) {
        cin >> contact[i];
    }

    string s;
    cout << "ingrese la cadena de busqueda: ";
    cin >> s;

    Solution obj;
    vector<vector<string>> output = obj.displayContacts(n, contact, s);

    cout << "\nResultados:\n";
    for (const auto& matches : output) {
        for (const string& name : matches) {
            cout << name << " ";
        }
        cout << endl;
    }

    return 0;
}
