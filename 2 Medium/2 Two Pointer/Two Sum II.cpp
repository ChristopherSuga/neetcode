/*
    Given a 1-indexed sorted int array & target:
    Return indices (added by 1) of 2 nums that add to target

    2 pointers, outside in, iterate i/j if sum is too low/high

    Time: O(n)
    Space: O(1)
*/

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> result;
        //while the pointers havent crossed
        while (l < r)
        {
            //if the numbers add up to the target end loop
            if (numbers[l] + numbers[r] == target)
            {
                result.push_back(l + 1);
                result.push_back(r + 1);
                return result;
            }
            //if the number is larger than the target decrement r pointer else increment the left pointer
            if (numbers[l] + numbers[r] > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return result;
    }
};