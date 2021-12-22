#include <iostream>

using namespace std;

/**
One Away: There are three types of edits that can be performed on strings: insert a character, remove a character,
or replace a character. Giving two strings, write a function to check if they are one edit (or zero edits) away.

Examples:

pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false

Solutions:
- brute force: do all operations and see if they match
- Book solution, check if one operation based on the lengths of the two strings. Choosing what edit operation to try respectively
**/

bool oneReplaceAway(string s1, string s2) {
    bool used_skip = false;

    for (int i = 0 ; i < s1.length() ; i++) {
        if (s1[i] != s2[i]) {
            if (used_skip) {
                return false;
            } else { 
                used_skip = true;
            }
        }
    }

    return true;
}

bool oneInsertAway(string s1, string s2) {
    bool used_insert = false;

    for (int i = 0 ; i < s2.length() ; i++) {
        if (!used_insert) {
            if (s1[i] != s2[i]) {
                used_insert = true;        
                i--;
            }
        } else {
            if (s1[i+1] != s2[i]) {
                return false;
            }
        }
    }

    return true;
}

/**
Book Solution
Time: O(n)
Space: O(1) 
**/
bool oneEditAway(string s1, string s2) {
    if (s1.length() == s2.length())
        return oneReplaceAway(s1, s2);
    else if (s1.length() > s2.length())
        return oneInsertAway(s1, s2);
    else //if (s1.length() < s2.length())
        return oneInsertAway(s2, s1);
}

int main() {
    cout << oneEditAway("pale", "ple") << endl;
    cout << oneEditAway("pales", "pale") << endl;
    cout << oneEditAway("pale", "bale") << endl;
    cout << oneEditAway("pale", "bae") << endl;
    cout << oneEditAway("pale", "pale") << endl;
}
