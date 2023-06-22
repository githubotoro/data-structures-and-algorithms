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
	int getSecondLargest(const vector<int> &arr) {
		int largest = INT_MIN;
        int second_largest = INT_MIN;
		
		for(auto &num: arr) {
            if(num > largest) {
                second_largest = largest;
                largest = num;
            } else if(num > second_largest && num != largest) {
                second_largest = num;
            }
        }

		return second_largest;
	}

    int getSecondSmallest(const vector<int> &arr) {
		int smallest = INT_MAX;
        int second_smallest = INT_MAX;
		
		for(auto &num: arr) {
            if(num < smallest) {
                second_smallest = smallest;
                smallest = num;
            } else if(num < second_smallest && num != smallest) {
                second_smallest = num;
            }
        }

		return second_smallest;
	}
};

int main() {
	yupuday();
	
	int n;
	cin>>n;

	vector<int> arr(n, 0);
	for(auto &num: arr) cin>>num;

	Solution S;
	cout<<S.getSecondLargest(arr)<<endl;
    cout<<S.getSecondSmallest(arr)<<endl;

	return 0;
}

// == IN ==
// 5
// 2 5 1 3 0

// == OUT ==
// 5