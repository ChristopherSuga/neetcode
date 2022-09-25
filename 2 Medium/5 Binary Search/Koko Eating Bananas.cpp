/*
	Given array of banana piles, guards are gone for h hours
	Return min int k such that can eat all banans within h
	Ex. piles = [3,6,7,11] h = 8 -> 4 (1@3, 2@6, 2@7, 3@11)

	Binary search, for each k count hours needed, store min

	Time: O(n x log m) -> n = # of piles, m = max # in a pile
	Space: O(1)
*/

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int n = piles.size();

		int low = 1;
		int high = 0;
		//loops through the vector to find the pile with the most bananas
		//k is between low(1) and high
		for (int i = 0; i < n; i++) {
			high = max(high, piles[i]);
		}

		int result = high;

		while (low <= high) {
			//finds the middle of k
			int k = low + (high - low) / 2;
			long int hours = 0;
			//calculates the time to eat based on k
			for (int i = 0; i < n; i++) {
				hours += ceil((double)piles[i] / k);
			}
			//if the time it takes to eat at speed k is less than time allowed saves the lowest speed
			if (hours <= h) {
				result = min(result, k);
				high = k - 1;
			}
			else {
				low = k + 1;
			}
		}

		return result;
	}
};