
#include <iostream>
using namespace std;
bool compare(string s1, string s2)
{
	// calculates length
	int n = s1.length();
	int m = s2.length();

	bool d[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			d[i][j] = false;
		}
	}
	// mark 1st position as true
	d[0][0] = true;

	// traverse for all DPi, j
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j <= s2.length(); j++) {

			// if possible for to convert i 
			// characters of s1 to j characters
			// of s2
			if (d[i][j]) {

				// if upper_case(s1[i])==s2[j]
				// is same
				if (j < s2.length() && 
					(toupper(s1[i]) == s2[j]))
					d[i + 1][j + 1] = true;

				// if not upper then deletion is 
				// possible
				if (!isupper(s1[i]))
					d[i + 1][j] = true;
			}
		}
	}

	return (d[n][m]);
}

// driver code
int main()
{
	string s1 = "daBcd";
	string s2 = "ABC";

	if (compare(s1, s2))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
