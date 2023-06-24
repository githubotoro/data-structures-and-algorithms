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
	int removeDuplicates(vector<int> &arr) {
		int last_pos = 0;

		for(int curr_pos = 0; curr_pos < arr.size(); curr_pos++) {
			if(arr[curr_pos] != arr[last_pos]) {
				last_pos++;
				arr[last_pos] = arr[curr_pos];
			}
		}

		return last_pos + 1;
	}
};

int main() {
	yupuday();
	
	int n;
	cin>>n;

	vector<int> arr(n, 0);
	for(auto &num: arr) cin>>num;

	Solution S;
	int newArrLength = S.removeDuplicates(arr);
	cout<<newArrLength<<"\n";

	for(int i=0; i<newArrLength; i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}

// == LINKS ==
// Leetcode -- https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// == IN ==
// 3
// 1 1 2

// == OUT ==
// 2
// 1 2 