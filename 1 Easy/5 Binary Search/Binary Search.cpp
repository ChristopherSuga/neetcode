/*
    Given sorted int array, search for a target value
    Ex. nums = [-1,0,3,5,9,12], target = 9 -> 4 (index)

    Since array is sorted, perform binary search

    Time: O(log n)
    Space: O(1)
*/

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        //two point iteration
        int l = 0;
        int r = nums.size() - 1;
        //loops as long as the left and right pointer have not crossed
        while (l <= r)
        {
            //calculates the middle numbers index
            int mid = (l + r) / 2;
            //if the middle number is lower than the target ignores everything to the left by updating the left pointer to the right of the middle by 1
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            //if the middle number is larger than the target ignores everything to the right by updating the right pointer to the left of the middle by 1
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            //if the middle number is neither larger or smaller thus equal then returns that number
            else
            {
                return mid;
            }
        }
        //returns -1 if it doesnt exist
        return -1;
    }
};