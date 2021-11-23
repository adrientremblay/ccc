#include <iostream>
#include <string>

using namespace std;

/**
URLify: Write a method to replace all spaces in a string with '%20' you may assume the string has sufficient space at the end to hold the additional
characters, and that you are given the "true" length of the string

Example:
"Mr John Smith    ", 13
"Mr%20John%20Smith"

Solutions:
- build a new string
- Copy to a new string
- Each time find a space, move everything over 
- Count each space, then go backwards and move everything to the exact correct place
**/

/**
Build New String Solution
Time: O(n^2)
Space: O(n)
**/
string build_new_string(string s, int last_char) {
    string ans;    

    for (int i = 0 ; i <= last_char ; i++) {
        char c = s[i];
        if (c == ' ')
            ans += "%20";
        else 
            ans += c;
    }

    return ans;
}

/**
Copy to New String Solution
Time: O(n)
Space: O(n)
**/
string copy_to_new_string(string s, int last_char) {
    string ans;    
    ans.resize(s.size());

    int j = 0;
    for (int i = 0 ; i <= last_char ; i++) {
        if (s[i] == ' ') {
            ans[j++] = '%';
            ans[j++] = '2';
            ans[j++] = '0';
        } else {
            ans[j++] = s[i]; 
        }
    }

    return ans;
}

/**
Count Spaces Solution
Time: O(n)
Space: O(1)
**/
string count_spaces(string s, int last_char) {
    int spaces = 0;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == ' ') {
            if (i == s.length() - 1 || s[i+1] == ' ')
                break;
    
            spaces++;
        }
    }

    for (int i = last_char ; i > 0 ; i--) {
        if (s[i] == ' ') {
            spaces--;
            s[i + (spaces*2)] = '%';
            s[i + (spaces*2) + 1] = '2';
            s[i + (spaces*2) + 2] = '0';
        } else {
            s[i + (spaces * 2)] = s[i];
        }
    } 

    return s;
}

int main() {
    cout << build_new_string("Mr John Smith    ", 12) << endl;
    cout << copy_to_new_string("Mr John Smith    ", 12) << endl;
    cout << count_spaces("Mr John Smith    ", 12) << endl;
}
