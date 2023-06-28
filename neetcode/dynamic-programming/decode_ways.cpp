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
	unordered_map<int, pair<bool, int>> dp;

public:
	int getDecodeWays(string str, int curr_index) {
		if(str[curr_index] == '0') return 0;
		if(curr_index >= str.length()) return 1;
		
		if(dp[curr_index].first == true) return dp[curr_index].second;
		
		int decode_ways = getDecodeWays(str, curr_index + 1);

		int next_index = curr_index + 1;
		if(next_index <= str.length()-1) {
			if(str[curr_index] == '1') {
				decode_ways += getDecodeWays(str, curr_index + 2);
			} else if(str[curr_index] == '2' && stoi(string(1, str[next_index])) <= 6) {
				decode_ways += getDecodeWays(str, curr_index + 2);
			}
		}

		dp[curr_index].first = true;

		return dp[curr_index].second = decode_ways;
	}

	int numDecodings(string s) {
		return getDecodeWays(s, 0);
	}
};

int main() {
	yupuday();
	
	string s;
	cin>>s;

	Solution S;
	cout<<S.numDecodings(s);

	return 0;
}

/*

== LINKS ==
-- Leetcode - https://leetcode.com/problems/decode-ways/
-- Neetcode - https://www.youtube.com/watch?v=6aEyTjOwlJU&list=PLot-Xpze53lcvx_tjrr_m2lgD2NsRHlNO&index=8

== IN ==
226 

== OUT ==
3

*/
