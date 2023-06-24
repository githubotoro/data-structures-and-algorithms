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
	int gcd(int a, int b) {
		if(b == 0) return a;
		else return gcd(b, a % b);
	}

	void rotateArray(vector<int> &arr, int k) {
		if(arr.size() <= 1) return;

		k = k % arr.size();
		if(k == 0) return;

		int swap_from = 0;
		int swap_to = k;

		int iters = 0;
		int req_iters = arr.size() - gcd(arr.size(), k);

		while(iters != req_iters) {
			swap(arr[swap_from], arr[swap_to]);

			swap_to = (swap_to + k) % arr.size();

			if(swap_from == swap_to) {
				swap_from += 1;
				swap_to = (swap_from + k) % arr.size();
			}
			
			iters++;
		}
	}
};

int main() {
	yupuday();
	
	int n;
	cin>>n;

	vector<int> arr(n, 0);
	for(auto &num: arr) cin>>num;

	int k;
	cin>>k;

	Solution S;
	S.rotateArray(arr, k);

	for(auto &num: arr) cout<<num<<" ";

	return 0;
}

/*

== WTF I DID ==
>> The Neetcode guy (check links) reversed the array 2 times & got the solution -- pretty cool.

>> I took an example (arr: [1 2 3 4 5 6 7], k:3, ans: [5 6 7 1 2 3 4]) + started staring at it **5 mins**
>> I realized that, the **only** thing changing at last is the index of the element. Moreover, if I keep swapping the numbers with each other -- one day I will get my answer, fr.
>> But the real question is -- which number to swap with whom?

>> In my taken example (0-based indexing -- to confuse y'all -- hehe):
-- 0th ele goes to 3rd
-- 1st goes to 4th
-- 2nd goes to 5th
-- 3rd goes to 6th
-- blah blah blah

>> Well, they are rotating in a cycle (obvs.) -- but, what if i fixed a single point and then, keep swapping from that point?

>> So this is what happened:
-- 0th ele goes to 3rd (swap_to) -- [4 2 3 1 5 6 7]
-- Now, we have "4" at 0th position -- but "4" is supposed to be at 6th position -- so, we swap 0th ele with 6th ele (swap_to) -- [7 2 3 1 5 6 4]
-- Now, we have "7" at 0th position -- but "7" is supposed to be at 2nd position (swap_to) -- so, we swap 0th ele with 2nd ele -- [7 2 3 1 5 6 4]
-- Calculation: swap_to = (swap_to + k) % arr.size()
-- We keep on doing this -- one day we will have "swap_to" value as the 0th position -- when it happens, our job is done.

>> Wanna know something cool about the above solution? -- we only traversed the array **once** -- forking cool!
>> But, the above solution failed for the test case -- arr: [-1 -100 3 99], k: 2
>> Because after 1st iteration, arr becomes [3 -100 -1 99] -- here, swap_to becomes "0" and loop ends.
>> So, I had to make one more iteration + increase the index
>> Thus, I cannot keep swapping from 0th index -- whenever I come back at 0, I will have to go the next index (1st in this case) and then swap it with [1st + k]th index -- (1st + k) % arr.size(), to be precise.

>> But, how the heck should I know that I have to go increase the index and then swap -- because in 1st example, I didn't had to.
>> I thought maybe there would be a relationship with % -- so, I needed to find how many iterations would I require in total -- I will keep on iterating and swapping till number of iterations required are not finished.
>> I made up this formula for total iterations (random try) -- req_iters = (arr.size() % k == 0) ? (arr.size() - 2) : (arr.size() - 1) 

>> I submitted, and guess what -- it failed at -- arr: [1 2], k:1 -- what the forking fork!!!
>> My formula said "0" iterations but there was supposed to be "1" iteration.

[I kept generating random relationships + formulas for 15 mins]

>> Finally, clicked on GFG solution (check links) -- where the 3rd solution used GCD & divided array into sets -- what the hell??? -- I won't do that drama, that's it!

>> Just after that, I realized that what if there's a relation between number of iterations & GCD -- well, my solution works, but I only need to know the total number of iterations, as simple as that.
>> Then, I did some random stuff:
-- GCD of 7 (arr.size) and 3 (k) is 1 => 7 - 1 = 6 (yeah, there were 6  iterations in that case)
-- GCD of 4 (arr.size) and 2 (k) is 2 => 4 - 2 = 2 (yeah yeah, there were 2 iterations in that case)
-- GCD of 2 (arr.size) and 1 (k) is 1 => 2 - 1 - 1 (forking hell -- that's it)
>> The formula for total iterations is: req_iters = arr.size() - GCD(arr.size(), k)
 
>> I may have spent an hour trying to figure this out -- but I proud of it, gg!

== LINKS ==
-- Leetcode - https://leetcode.com/problems/rotate-array/
-- Neetcode - https://www.youtube.com/watch?v=BHr381Guz3Y
-- GFG - https://www.geeksforgeeks.org/array-rotation/

== IN ==
4
1 2 3 4 
2

== OUT ==
3 4 1 2 

*/
