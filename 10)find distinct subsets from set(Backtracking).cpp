#include <iostream>
using namespace std;

// Maximum number of elements in the set
const int MAX_ELEMENTS = 10;
const int MAX_SUBSETS = 1024;

// Function to sort the array (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to check if a subset is unique
bool isUnique(int subsets[MAX_SUBSETS][MAX_ELEMENTS], int subset[], int subsetSize, int subsetCount) {
    for (int i = 0; i < subsetCount; i++) {
        bool identical = true;
        for (int j = 0; j < subsetSize; j++) {
            if (subsets[i][j] != subset[j]) {
                identical = false;
                break;
            }
        }
        if (identical) {
            return false;
        }
    }
    return true;
}

// Function to find all distinct subsets of a given set
void findPowerSet(int arr[], int n) {
    int subsets[MAX_SUBSETS][MAX_ELEMENTS] = {0};
    int subsetCount = 0;
    int totalSubsets = 1 << n; // 2^n subsets

    bubbleSort(arr, n); // Sort the array to handle duplicates

    for (int mask = 0; mask < totalSubsets; mask++) {
        int subset[MAX_ELEMENTS] = {0};
        int subsetSize = 0;

        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                subset[subsetSize++] = arr[j];
            }
        }

        // Check if the subset is unique before adding
        if (isUnique(subsets, subset, subsetSize, subsetCount)) {
            for (int k = 0; k < subsetSize; k++) {
                subsets[subsetCount][k] = subset[k];
            }
            subsetCount++;
        }
    }

    // Print all unique subsets
    for (int i = 0; i < subsetCount; i++) {
        for (int j = 0; j < n; j++) {
            if (subsets[i][j] != 0) {
                cout << subsets[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Driver code
int main() {
    int arr[] = {10, 12, 12};
    int n = 3; // Size of the array

    findPowerSet(arr, n);

    return 0;
}
