// A Dynamic Programming solution
// for subset sum problem
#include <iostream>
using namespace std;

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool count(int element[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..i-1] with sum
    // equal to j
    bool set[n + 1][sum + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        set[i][0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        set[0][i] = false;

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < element[i - 1])
                set[i][j] = set[i - 1][j];
            if (j >=element[i - 1])
                set[i][j]
                    = set[i - 1][j]
                      || set[i - 1][j - element[i - 1]];
        }
    }

    return set[n][sum];
}

// Driver code
int main()
{
    int element[] = { 1,2,3 };
    int sum =3 ;
    int n = sizeof(element) / sizeof(element[0]);
    if (count(element, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}


