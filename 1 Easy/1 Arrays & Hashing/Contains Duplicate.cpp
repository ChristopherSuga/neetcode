/*
    Given int array, return true if any value appears at least twice
    Ex. nums = [1,2,3,1] -> true, nums = [1,2,3,4] -> false

    If seen num previously then has dupe, else insert into hash set

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //unordered_set is a type of hash set
        unordered_set<int> s;
        // loops through array
        for (int i = 0; i < nums.size(); i++) {
            /*s.find(nums[i]) looks for the number in the unordered set and returns s.end() if the number is not found
            * if nums[i] is found in the unordered set then the find function would return an iterator to the number instead of s.end() returning true
            */
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            //if the number is not found in the set the number is added
            s.insert(nums[i]);
        }

        return false;
    }
};