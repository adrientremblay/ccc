#include <iostream>

using namespace std;

/**
Rotate Matrix: Given an image represeded by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place.

Solutions:
- With a new array (pretty trivial)
    - iterate through each element, and move it to the location it's supposed to go to in the final array
- In place 
    - Build arrays for each column O(n)
**/

void rotate_matrix_1(int arr[3][3]) {
    arr[1][1] = 0;
}

int main() {
    int test_case_1[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    rotate_matrix_1(test_case_1);
    cout << test_case_1[1][1] << endl;
}
