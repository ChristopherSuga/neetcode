/*
    Given string, find longest substring w/o repeating chars
    Ex. s = "abcabcbb" -> 3 "abc", s = "bbbbb" -> 1 "b"

    Sliding window, expand if unique, contract if duplicate

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters;

        int i = 0;
        int j = 0;

        int result = 0;
        //loops through the entire string
        while (j < s.size()) {
            //if the letter is not in the set adds it
            if (letters.find(s[j]) == letters.end()) {
                letters.insert(s[j]);
                //the largest length gets updated. j-i+1 is the length of the string
                result = max(result, j - i + 1);
                j++;
            }
            //if the letter is in the set already the left pointer gets increased and the repeated letter gets removed from the set
            else {
                letters.erase(s[i]);
                i++;
            }
        }

        return result;
    }
};