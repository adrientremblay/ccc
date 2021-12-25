#include <iostream>
#include <vector>

using namespace std;

/**
Rotate Matrix: Given an image represeded by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place.

Solutions:
- With a new array (pretty trivial)
    - iterate through each element, and move it to the location it's supposed to go to in the final array
- In place 
    - Build arrays for each column O(n)
**/

/**
Works by creating new rows for each column
**/
vector<vector<int>> rotate_matrix_1(vector<vector<int>> arr) {
    arr[1][1] = 0;
    return arr;
}


/**
Utility function
**/
void print_2d_array(vector<vector<int>> arr) {
}

int main() {
    vector<vector<int>> test_case_1 {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    cout << rotate_matrix_1(test_case_1)[1][1] << endl;
}
