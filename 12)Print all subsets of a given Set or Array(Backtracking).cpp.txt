#include <iostream>
using namespace std;

const int MAX_SIZE = 10;  // Max size of the input set
int res[MAX_SIZE][MAX_SIZE];  // 2D array to store subsets
int resSize = 0;  // To keep track of the number of subsets

// Function to print a subset
void printSubset(int subset[], int subsetSize) {
    for (int i = 0; i < subsetSize; i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

// Recursive function to generate all subsets
void calcSubset(int A[], int n, int subset[], int subsetSize, int index) {
    // Add the current subset to the result
    for (int i = 0; i < subsetSize; i++) {
        res[resSize][i] = subset[i];
    }
    resSize++;

    // Generate subsets by including and excluding elements
    for (int i = index; i < n; i++) {
        // Include the current element in the subset
        subset[subsetSize] = A[i];

        // Recursively generate subsets with the current element included
        calcSubset(A, n, subset, subsetSize + 1, i + 1);
    }
}

// Function to generate all subsets of the array
void subsets(int A[], int n) {
    int subset[MAX_SIZE];  // Array to store the current subset
    calcSubset(A, n, subset, 0, 0);
}

int main() {
    int array[] = { 1, 2, 3 };  // Input array
    int n = 3;  // Size of the array

    subsets(array, n);  // Generate all subsets

    // Print the generated subsets
    for (int i = 0; i < resSize; i++) {
        int subsetSize = 0;
        while (res[i][subsetSize] != 0) {
            subsetSize++;
        }
        printSubset(res[i], subsetSize);
    }

    return 0;
}
