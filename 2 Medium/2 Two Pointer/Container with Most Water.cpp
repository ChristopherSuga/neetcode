/*
    Given array of heights, find max water container can store
    Ex. height = [1,8,6,2,5,4,8,3,7] -> 49, (8 - 1) x min(8, 7)

    2 pointers outside in, greedily iterate pointer w/ lower height

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxArea;
    }
};