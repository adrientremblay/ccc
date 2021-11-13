#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

/**
Brute force two loops solution
Time: O(n^2)
Space: O(1)
**/
bool brute_force(string s) {
    for (int i = 0 ; i < s.size() ; i++) {
        for (int j = 0 ; j < s.size() ; j++) {
            if (i != j && s[i] == s[j]) 
                return false;
        }
    }

    return true;
}

/**
Sort then check solution
Time: O(n*log(n)) assuming heap sort
Space: 
**/
bool sort_first(string s) {
    vector<char> v(s.begin(), s.end());
    sort(v.begin(), v.end());
    
    int n = v.size();
    for (int i = 0 ; i < n - 1 ; i++) {
        if (v[i] == v[i+1])
            return false;
    }

    return true;
}

/**
Bit array solution
Time: O(n)
Space: O(1) the ASCII charset size is a constant
**/
bool bit_array(string s) {
    if (s.size() > 128)
        return false;

    vector<bool> alphabet(128, false);
    for (int i = 0 ; i < s.size() ; i++) {
        int index = (int) s[i];
        if (alphabet[index] == true)
            return false;
        else
            alphabet[index] = true;
    }

    return true;
}

int main() {
    vector<string> test_cases = {"hello", "world", "", "a", "h4ck3r"};

    for (int i = 0 ; i < test_cases.size() ; i++) {
        cout << "Test Case: " << test_cases[i] << endl;
        cout << brute_force(test_cases[i]) << endl;
        cout << sort_first(test_cases[i]) << endl;
        cout << bit_array(test_cases[i]) << endl;
    }
}
