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
- Copy to a new string
- Each time find a space, move everything over 
- Count each space, then go backwards and move everything to the exact correct place
**/

string count_spaces(string s) {
    int spaces = 0;
    int last_char = 0;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == ' ') {
            if (i == s.length() - 1 || s[i+1] == ' ')
                break;
    
            spaces++;
        } else {
            last_char = i;
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
    string test_cases[] = { "Mr John Smith    " };
    for (string s : test_cases) {
        cout << s << endl;
        cout << "COUNT SPACES: " << count_spaces(s) << endl;
    }
}
