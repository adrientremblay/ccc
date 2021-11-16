#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
Check Permutation: Given two strings, write a method to decide if one is a permutation of the other

Example:

"sadeas" and "dassea"

Solutions:
- sort both and compare, see if they are equal
- hash map and check if they are equal 

**/

/**
Sort Solution
Time: O(N*logN)
Space: O(1)
**/
bool sort_both(string a, string b) {
    if (a.length() != b.length())
        return false;

    vector<char> va(a.begin(), a.end());
    sort(va.begin(), va.end());

    vector<char> vb(b.begin(), b.end());
    sort(vb.begin(), vb.end());

    return va == vb;
}

/**
Hash Map Solution
Time: O(N)
Space: O(1)
**/
bool hash_map(string a, string b) {
    if (a.length() != b.length())
        return false;

    unordered_map<char, int> map;
    
    for (char c : a)
        if (!map.contains(c))
            map[c] = 1;
        else
            map[c]++;

    for (char c : b)
        if (!map.contains(c))
            return false;
        else
            map[c]--;

    for (pair<char, int> element : map) 
        if (element.second != 0)
            return false;
    
    return true;
}

/**
Char Count Array Solution
Time: O(N)
Space: O(1)
**/
bool count_array(string a, string b) {
    if (a.length() != b.length())
        return false;
    
    int char_count[128] = { 0 };

    for (char c : a)
        char_count[(int) c]++;

    for (char c : b) 
        if (--char_count[(int) c] < 0)
            return false;

    return true ;
}

int main() {
    string tests[][2] = { {"sadeas", "dassea"}, {"", ""}, {"a", "a"}, {"ball", "cars"} };
    
    for (auto& test : tests) {
        cout << test[0] << " " << test[1] << endl;
        cout << "SORT SOLUTION: " << hash_map(test[0], test[1]) << endl;
        cout << "HASH MAP SOLUTION: " <<  hash_map(test[0], test[1]) << endl;
        cout << "CHAR COUNT ARRAY: " <<  count_array(test[0], test[1]) << endl;
    }
}
