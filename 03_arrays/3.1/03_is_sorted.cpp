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
	bool isSorted(const vector<int> &arr) {
		if(arr.size() == 1) return true;

		for(int i=1; i<arr.size(); i++) {
			if(arr[i] < arr[i-1]) return false;
		}

		return true;
	}
};

int main() {
	yupuday();
	
	int n;
	cin>>n;

	vector<int> arr(n, 0);
	for(auto &num: arr) cin>>num;

	Solution S;
	cout<<S.isSorted(arr);

	return 0;
}

// == IN ==
// 5
// 1 2 3 4 5

// == OUT ==
// 1