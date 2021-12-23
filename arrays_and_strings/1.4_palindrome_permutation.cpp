#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of the letters. The palindrome does not need to be limited to just dictionary words.

notes:
- ignore spaces

solutions:
- brute force: generate every single permutation, check each one if it's a permutation (not coding this)
- hash map, check every char has an even count, except at most one char
- sort and check that every num has even count, except at most one char (not coding this)
- bit vector crap (not coding this)
- bitmap solution

Ex:
Tact Coa
**/

/**
Hashmap solution
Time: O(n)
Space: (n)
**/
bool hashmap(string s) {
    unordered_map<char, int> counts; 
    for (char c : s) {
        if (c == ' ')
            continue;
        c = tolower(c);
    
        if (counts.find(c) == counts.end())
            counts[c] = 1;
        else 
            counts[c]++;
    }
    
    bool middle_found = false;
    for (const auto &pair : counts) {
        if (pair.second % 2 != 0) {
            if (middle_found)
                return false;
            middle_found = true;
        }
    }
    
    return true;
}

/**
Bitmap Solution
Time: O(n)
Space: O(n)
**/
bool bitmap(string s) {
    bool odds[26] = {false};

    for (char c : s) {
        int index = ((int)'z') - ((int)tolower(c));
        odds[index] = !odds[index];
    }

    bool middle_found = false;
    for (bool b : odds) {
        if (b) {
            if (middle_found)
                return false;
            middle_found = true;
        }
    }

    return true;
}

int main() {
    string tests[] = { "Tact Coa", "Tact Coat", "aaa", "aaaB", "" };

    for (string s : tests) {
        cout << s << hashmap(s) << bitmap(s) << endl;
    }

    return 0;
}
