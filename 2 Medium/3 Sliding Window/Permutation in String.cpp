/*
    Given 2 strings, return true if s2 contains permutation of s1
    Ex. s1 = "ab", s2 = "eidbaooo" -> true, s2 contains "ba"

    Sliding window, expand + count down char, contract + count up char

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        //if the permutation is longer than the actual string automatically false
        if (m > n) {
            return false;
        }
        vector<int> count(26);
        //iterates through the string with a window with the same length of the permutation length
        for (int i = 0; i < m; i++) {
            //increments the char of the permutation
            count[s1[i] - 'a']++;
            //decrements the char of the string
            count[s2[i] - 'a']--;
        }
        //calls isPermutation on the count vector
        if (isPermutation(count)) {
            return true;
        }
        //iterates through the rest of the string
        for (int i = m; i < n; i++) {
            //slides the window by subtracting i from the vector and adding i-m
            count[s2[i] - 'a']--;
            count[s2[i - m] - 'a']++;
            //calls is permutation to check if new string is permutation
            if (isPermutation(count)) {
                return true;
            }
        }

        return false;
    }
private:
    //loops through the entire vector and if the 
    bool isPermutation(vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};