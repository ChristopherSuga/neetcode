/*
    Given an integer array nums, return an array such that:
    answer[i] is equal to the product of all elements of nums except nums[i]
    Ex. nums = [1,2,3,4] -> [24,12,8,6], nums = [-1,1,0,-3,3] -> [0,0,9,0,0]

    Calculate prefix products forward, then postfix backwards in a 2nd pass

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        //creates a vector of size n all with values of 1
        vector<int> result(n, 1);
        int prefix = 1;
        //loops through the vector from left to right
        for (int i = 0; i < n; i++) {
            //stores the prefix in the result output
            result[i] = prefix;
            //updates the prefix to include the current number
            prefix = prefix * nums[i];
        }

        int postfix = 1;
        //loops through the vector from right to left
        for (int i = n - 1; i >= 0; i--) {
            //stores the new result as the saved prefix multiplied by the postfix
            result[i] = result[i] * postfix;
            //updates the postfix to include the current number
            postfix = postfix * nums[i];
        }

        return result;
    }
};