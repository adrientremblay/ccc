#include <iostream>
#include <vector>

using namespace std;


/** 
Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0 

Solutions:
- Brute force
    - make a copy of the matrix
    - loop through matrix item by item and zero rows and columns as you go
- optimal
    - make bool array representing the columns and rows of size N and M respectively
    - loop through each of these arrays. if false search for 0 and if found mark column and row to be zeroed
    - make copy of the matrix
    - zero all the rows and columns
**/

/**
Solution 1: brute force
Time: O(N^2)
Space: O(N^2)
**/
vector<vector<int>> zero_matrix_1(vector<vector<int>> matrix) {
    int M = matrix.size();
    int N = matrix[0].size();

    bool rows[M] = {false};
    bool cols[N] = {false};
    
    for (int i = 0 ; i < M ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }    

    vector<vector<int>> ans(matrix);

    for (int i = 0 ; i < M ; i++){
        if (!rows[i])
            continue;
        
        for (int j = 0 ; j < N ; j++) {
            ans[i][j] = 0;
        }
    }
    for (int i = 0 ; i < N ; i++){
        if (!cols[i])
            continue;

        for (int j = 0 ; j < M ; j++) {
            ans[j][i] = 0;
        }
    }

    return ans;
}

/**
Utility function, print an MxN matrix
**/
void print_matrix(vector<vector<int>> matrix) {
    int M = matrix.size();
    int N = matrix[0].size();
    for (int i = 0 ; i < M ; i++) {
        cout << "{";
        for (int j = 0 ; j < N ; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<vector<int>> test_case_1 {
        { 1, 0, 3, 0 },
        { 5, 6, 7, 8 },
        { 9, 0, 11, 12 }
    };

    print_matrix(zero_matrix_1(test_case_1));
}
