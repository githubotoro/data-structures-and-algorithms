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
	bool isValidAnagram(string &str1, string &str2) {
		if(str1.length() != str2.length()) return false;

		unordered_map<char, int> mp;

		for(int i=0; i<str1.length(); i++) {
			mp[str1[i]]++;
			mp[str2[i]]--;
		}

		for(auto itr: mp) {
		   if(itr.second != 0) return false;
		}

		return true;
	}
};

int main() {
	yupuday();
	
	string str1, str2;
	cin>>str1>>str2;

	Solution S;
	cout<<S.isValidAnagram(str1, str2);

	return 0;
}

/*

== WTF I DID ==
>> I tried to solve this using XOR technique -- if all the elements in the 2 strings are same, they all will appear exactly twice -- XOR of two same numbers is 0 -- so, we keep on XORing the ASCII values of characters and if we end the result with 0, its an Anagram and if it is 1, its not an anagram -- simple, right?

>> Well, when i submitted on Leetcode -- it failed for the test case -- s: "aa", t: "bb"
>> I didn't think about that case -- so, instead of finding that arcane code which will achieve the solution using XOR and saving the world; I went with the usual Hashmap solution, coz' I believe in democracy...

>> Just in case, y'all want to find the solution using XOR -- here is the incorrect version I wrote -- do let me know if you are able to figure it out -- thanks! :)

bool isAnagram(string str1, string str2) {
	if(str1.length() != str2.length()) return false;

	int xor_result = 0;

	for(int i=0; i<str1.length(); i++) {
		xor_result ^= int(str1[i]);
		xor_result ^= int(str2[i]);
	}

	if(xor_result == 0) return true;
	else return false;
}

== LINKS ==
-- Leetcode - https://leetcode.com/problems/valid-anagram/
-- Neetcode - https://www.youtube.com/watch?v=9UtInBqnCgA&list=PLot-Xpze53lfQmTEztbgdp8ALEoydvnRQ

== IN ==
anagram
nagaram

== OUT ==
1

*/
