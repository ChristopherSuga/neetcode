/*
    Given large int as an array, add 1 (consider carry)
    Ex. digits = [1,2,3] -> [1,2,4]

    From right to left, keep carrying until digit < 9, add 1

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //iterates over the array starting from the end
        for (int i = digits.size() - 1; i >= 0; i--) {
            //if the end number is not 9 then just all 1 and return array
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            //if it is 9 then changes the 9 to a 0 and moves on to the next number
            digits[i] = 0;
        }
        //base case for if the array starts with a 9
        //pushes makes the first number 1 and pushes a 0
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};