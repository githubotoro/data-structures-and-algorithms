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
	int getLargest(const vector<int> &arr) {
	 int largest = INT_MIN;
		
		for(auto &num: arr) largest = max(num, largest);

		return largest;
	}
};

int main() {
	yupuday();
	
	int n;
	cin>>n;

	vector<int> arr(n, 0);
	for(auto &num: arr) cin>>num;

	Solution S;
	cout<<S.getLargest(arr);

	return 0;
}

// == IN ==
// 5
// 2 5 1 3 0

// == OUT ==
// 5