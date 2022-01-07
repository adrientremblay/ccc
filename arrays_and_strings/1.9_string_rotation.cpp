#include <iostream>
#include <string>

using namespace std;

/**
String Rotation: Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings,
s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring

Example:

waterbottle and erbottlewat

Solutions:
**/

bool is_substring(string s1, string s2) {
    return s1.find(s2) != string::npos ? true :  false;
}

/**
Solution 1
Time: O(N) 
Space: O(1)
**/
bool is_rotation_1(string s1, string s2) {
    return is_substring(s2 + s2, s1);
}

int main() {
    cout << is_rotation_1("waterbottle", "erbottlewat") << endl;
    cout << is_rotation_1("fish", "dish") << endl;
}
