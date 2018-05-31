/ SequenceFinder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> seq(vector<int> a);

int main()
{	//Van der Corput Sequence
	vector<int> a = { 0 , 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	vector<int> ans(16);

	ans = seq( a);
	int m = ans.size();
	for (int n = 0; n < (signed)ans.size(); n++) {
	cout << "  " << ans[n];
	}

    return 0;
}

vector<int> seq(vector<int> a) {
	vector<int> ans(16);
	//initialize 3 arrays: original sequence a, temp array, and answer array
	vector<int> temp(16);

	int m = 0; 
	for (int n = 0; n < 16; n++) {
		if (n == 0) {
			temp[m] = a[n];
			continue;
		}
		if (a[n] > a[n - 1]) {
			temp[m] = a[n];
		}
		else if (a[n] <= a[n - 1]) {

			if (ans[m-1] <= temp[m-1]) {

				for (int p = 0; p < (signed)temp.size(); p++) {
					ans[p] = temp[p];

				}
			}
			m = 0; 
			temp[m] = a[n];
		}
		m++;
	}

	return ans;
}

