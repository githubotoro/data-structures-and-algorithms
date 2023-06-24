#include <bits/stdc++.h>

using namespace std;

void yupuday() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

class Solution {
public:
	bool isSortedRotated(const vector<int> &arr) {
		int invalid_pairs = 0;

		for(int i=1; i<arr.size(); i++) {
			if(arr[i]<arr[i-1]) invalid_pairs++;
		}

		if(arr.size() > 2) {
			if(arr[0] < arr[arr.size()-1]) invalid_pairs++;
		}

		if(invalid_pairs > 1) return false;
		else return true;
	}
};

int main() {
	yupuday();
	
	int n;
	cin>>n;

	vector<int> arr(n, 0);
	for(auto &num: arr) cin>>num;

	Solution S;
	cout<<S.isSortedRotated(arr);

	return 0;
}

// == LINKS ==
// Leetcode -- https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// == IN ==
// 5
// 1 2 3 4 5

// == OUT ==
// 1