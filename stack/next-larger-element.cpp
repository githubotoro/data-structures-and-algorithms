#include <bits/stdc++.h>

using namespace std;

void stayTORO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

int traverse(stack <int> &s, const int &ele) {
	// If stack is empty, return -1
	// else if top of stack is greater than given element, return top
	if (s.size() == 0) return -1;
	else if (s.top() > ele) return s.top();
	
	// If base condition is false, then pop from stack
	// and call traverse function again
	s.pop();
	traverse(s, ele);
}

int main() {
	stayTORO();

	int n;
	cin>>n;

	int arr[n];
	int ans[n];

	stack <int> s;

	// Taking input array
	for(int i=0; i<n; i++) cin>>arr[i];

	// Traverse array from right side
	for(int i=n-1; i>=0; i--) {
		// Calling recursive function
		ans[i] = traverse(s, arr[i]);

		// At last, push element into the stack
		s.push(arr[i]);
	}

	// Displaying output array
	for(int i=0; i<n; i++) cout<<ans[i]<<" ";
	
	return 0;
}

// IN
// 8
// 2 0 4 5 3 1 2 6
// OUT
// 4 4 5 6 6 2 6 -1 