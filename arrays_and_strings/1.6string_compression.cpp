#include <iostream>
#include <string>

using namespace std;

/**
String Compression: Implement a method to perform basic string compression using the counts of repeated characters.
For example, the string aabcccccaaa would be a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a-z).

Ex: aabcccccaaa -> a2b1c5a3
**/

/**
Intuitive Solution
Time: O(n) where n is the length of the string
Space: O(x) where x is the number of unique characters in the string
**/

string string_compression(string s) {
    if (s.length() == 0)
        return "";

    string compressed = ""; 

    char current = s[0];
    int count = 0;
    for (char c : s) {
        if (c == current) {
            count++;
        } else {
            compressed += current + to_string(count);
            current = c;
            count = 1;
        }
    }
    compressed += current + to_string(count);

    return compressed.length() < s.length() ? compressed : s; 
} 

int main() {
    cout << "aabcccccaaa -> " << string_compression("aabcccccaaa") << endl;
    cout << "abcd -> " << string_compression("abcd") << endl;
    cout << " -> " << string_compression("") << endl;
}
