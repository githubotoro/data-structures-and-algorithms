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
	static bool compare_strings(string a, string b) {
		return b.size() > a.size();
	}

	string longestPalindrome(string str) {
		string longest_palindrome = "";

		int low, high;
		string odd_length_palindrome, even_length_palindrome;

		for(int i=0; i<str.size(); i++) {
			odd_length_palindrome = string(1, str[i]);
			low = i-1;
			high = i+1;

			while(low >= 0 && high <= str.size()-1 && str[low] == str[high]) {
				odd_length_palindrome = str[low] + odd_length_palindrome + str[high];
				low--;
				high++;
			}

			even_length_palindrome = "";
			low = i;
			high = i+1;

			while(low >= 0 && high <= str.size()-1 && str[low] == str[high]) {
				even_length_palindrome = str[low] + even_length_palindrome + str[high];
				low--;
				high++;
			}

			longest_palindrome=max({longest_palindrome, odd_length_palindrome, even_length_palindrome}, compare_strings);
		}

		return longest_palindrome;
	}
};

int main() {
	yupuday();
	
	string s;
	cin>>s;

	Solution S;
	cout<<S.longestPalindrome(s);

	return 0;
}

/*

== LINKS ==
-- Leetcode - https://leetcode.com/problems/longest-palindromic-substring/
-- Neetcode - https://www.youtube.com/watch?v=XYQecbcd6_c&list=PLot-Xpze53lcvx_tjrr_m2lgD2NsRHlNO&index=7

== IN ==
babad 

== OUT ==
bab

*/
