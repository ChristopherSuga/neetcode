/*
    Given int array & target, return indices of 2 nums that add to target
    Ex. nums = [2,7,11,15] & target = 9 -> [0,1], 2 + 7 = 9

    At each num, calculate complement, if exists in hash map then return

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        //loops through the vector of numbers
        for (int i = 0; i < nums.size(); i++) {
            //calculates the complement number that is needed to satisfy the addition
            int complement = target - nums[i];
            //checks if the complement is in the map
            if (m.find(complement) != m.end()) {
                //if the complement is in the map pushes the complements index to the result and pushes the index of current number that satisfies the complement and exits the loop
                result.push_back(m[complement]);
                result.push_back(i);
                break;
            }
            //if the complement is not currently in the map then the number is inserted in
            else {
                m.insert({ nums[i], i });
            }
        }

        return result;
    }
};