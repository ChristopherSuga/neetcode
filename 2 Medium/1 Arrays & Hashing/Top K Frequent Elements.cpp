/*
    Given an integer array nums & an integer k, return the k most frequent elements
    Ex. nums = [1,1,1,2,2,3] k = 2 -> [1,2], nums = [1] k = 1 -> [1]

    Heap -> optimize w/ freq map & bucket sort (no freq can be > n), get results from end
*/

// Time: O(n log k)
// Space: O(n + k)

class Solution {
    topkFrequent([1, 1, 1, 2, 2, 3], 2);
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> m;
        //loop that goes through entire vector
        for (int i = 0; i < n; i++) {
            //increments the corresponding number once
            m[nums[i]]++;
        }

        vector<vector<int>> buckets(n + 1);
        //iterates over the map
        for (auto it = m.begin(); it != m.end(); it++) {
            //flips the values of the original map (a,b) -> (b,a)
            buckets[it->second].push_back(it->first);
        }

        vector<int> result;
        //loop that decrements based off of the maximum amount of values given in initial vector
        for (int i = n; i >= 0; i--) {
            //stops the loop once k is reached
            if (result.size() >= k) {
                break;
            }
            if (!buckets[i].empty()) {
                //starts insertion at the end of the vector so that the number with the most occurences shows on the left, .begin and .end specify where the value begins
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }

        return result;
    }
};