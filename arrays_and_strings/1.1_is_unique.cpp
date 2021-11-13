#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use
 * additional data structures?
 * 
 * Possible solutions:
 * hash map / bit array
 * brute force : two loops
 * sort, and then search for same elements next to each other
 *
 **/

bool bit_array(string s) {
    if (s.size() > 128)
        return true;

    vector<bool> alphabet(128, false);
    for (int i = 0 ; i < s.size() ; i++) {
        int index = (int) s[i];
        if (alphabet[index] == true)
            return true;
        else
            alphabet[index] = true;
    }

    return false;
}

int main() {
    cout << bit_array("penis") << endl;
    cout << bit_array("hello") << endl;
}
