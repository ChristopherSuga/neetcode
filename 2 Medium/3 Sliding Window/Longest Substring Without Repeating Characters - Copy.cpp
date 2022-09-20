/*
    Given a string s & an int k, can change any char k times:
    Return length of longest substring containing same letter
    Ex. s = "ABAB" k = 2 -> 4 "AAAA", s = "AABABBA" k = 1 -> 4

    Sliding window, expand if can change char, contract if > k

    Time: O(n)
    Space: O(26)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;

        int i = 0;
        int j = 0;

        int result = 0;

        while (j < s.size()) {
            //increments the index of the corresponding letter by 1
            count[s[j] - 'A']++;
            //checks which letter appears the most in the string
            maxCount = max(maxCount, count[s[j] - 'A']);
            //if the chars that would need to be replace is greater than the allowed replacements then the first letter is removed and the window is moved
            if (j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }
            //the max length is updated and the right pointer is incremented
            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};