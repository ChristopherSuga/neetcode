/*
    Given an integer array nums & an integer k, return the k most frequent elements
    Ex. nums = [1,1,1,2,2,3] k = 2 -> [1,2], nums = [1] k = 1 -> [1]

    Heap -> optimize w/ freq map & bucket sort (no freq can be > n), get results from end
*/

// Time: O(n log k)
// Space: O(n + k)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        //iterates over the vector of numbers
        for (int num : nums) {
            //the key num gets incremented by 1
            map[num]++;
        }
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int)map.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};