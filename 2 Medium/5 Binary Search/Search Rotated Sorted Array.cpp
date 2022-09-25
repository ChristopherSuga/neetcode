/*
    Given array after some possible rotation, find if target is in nums
    Ex. nums = [4,5,6,7,0,1,2] target = 0 -> 4 (value 0 is at index 4)

    Modified binary search, if low <= mid left sorted, else right sorted

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            //if in left sorted portion
            if (nums[low] <= nums[mid]) {
                //if the leftmost number is lower than the target and the target is less than the middle then the number is in the left portion
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                //if not then the number might be in the right portion
                else {
                    low = mid + 1;
                }
            }
            //if in right sorted portion
            else {

                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};