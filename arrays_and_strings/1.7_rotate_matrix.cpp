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
Solution 1: Works by creating new rows for each column, transferring new values
Time: O(N^2)
Space: O(N^2)
**/
vector<vector<int>> rotate_matrix_1(vector<vector<int>> matrix) {
    int N = matrix.size();
    vector<vector<int>> ans(N, vector<int>(N));

    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
            ans[j][N-i-1] = matrix[i][j];

    return ans;
}

/**
Utility function, print an NxN matrix
**/
void print_matrix(vector<vector<int>> matrix) {
    int N = matrix.size();
    for (int i = 0 ; i < N ; i++) {
        cout << "{";
        for (int j = 0 ; j < N ; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<vector<int>> test_case_1 {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    print_matrix(rotate_matrix_1(test_case_1));
}
