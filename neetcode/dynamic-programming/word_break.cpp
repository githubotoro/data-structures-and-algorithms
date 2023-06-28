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
	unordered_map<string, int> dp;

public:
	bool canSegment(string str, unordered_map<string, bool> &dict) {
		if(str.size() == 0) return true;

		if(dp[str] != 0) {
			return dp[str] == 1 ? true : false;
		}

		for(int i=1; i<=str.size(); i++) {
			if(dp[str.substr(i)] == 0) {
				dp[str.substr(i)] = canSegment(str.substr(i), dict) == true ? 1 : -1;
			}

			bool can_segment = dp[str.substr(i)] == 1 ? true : false;

			if(dict[str.substr(0, i)] == true && can_segment) {
				return dp[str] = true;
			}
		}

		return dp[str] = false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_map<string, bool> dict;

		for(auto word : wordDict) dict[word] = true;
		
		return canSegment(s, dict);
	}
};

int main() {
	yupuday();
	
	string s;
	cin>>s;

	vector<string> wordDict;

	string word;
	while(cin>>word) {
		wordDict.push_back(word);
	}

	Solution S;
	cout<<S.wordBreak(s, wordDict);

	return 0;
}

/*


== LINKS ==
-- Leetcode - https://leetcode.com/problems/word-break/
-- Neetcode - https://www.youtube.com/watch?v=Sx9NNgInc3A&list=PLot-Xpze53lcvx_tjrr_m2lgD2NsRHlNO&index=6

== IN ==
applepenapple
apple pen 

== OUT ==
1

*/
