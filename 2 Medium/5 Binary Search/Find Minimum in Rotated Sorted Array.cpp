/*
    Given sorted array after some rotation, find min value
    Ex. nums = [3,4,5,1,2] -> 1, nums = [4,5,6,7,0,1,2] -> 0

    Binary search + ensuring we never disqualify possible min value

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // not left <= right since not searching for target
        while (left < right) {
            int mid = left + (right - left) / 2;
            // ex. [3,4,5,6,7,8,9,1,2], mid = 4, right = 8
            // nums[mid] > nums[right], min must be right
            if (nums[mid] > nums[right]) {
                // never consider mid bc know for sure not min
                left = mid + 1;
                // ex. [8,9,1,2,3,4,5,6,7], mid = 4, high = 8
                // nums[mid] <= nums[right], min must be left
            }
            else {
                // consider mid still bc could be min
                right = mid;
            }
        }

        // low lands on correct value, never disqualified mins
        return nums[left];
    }
};