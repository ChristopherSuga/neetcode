/*
    Given 2 strings, return true if anagrams (same letters diff order)
    Ex. s = "anagram" & t = "nagaram" -> true, s = "rat" & t = "car" -> false

    Count chars, strings should have same # of chars if anagram

    Time: O(n)
    Space: O(26)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        //base case that checks size of both strings
        if (s.size() != t.size()) {
            return false;
        }
        //creates a vector of ints with a size of 26 for each letter in the alphabet
        vector<int> count(26);
        //loops over the first string s
        for (int i = 0; i < s.size(); i++) {
            //increments the count by calculating the ascii value of the letter (A = 0) (B = 1) etc...
            count[s[i] - 'a']++;
        }
        //loops over the second string t
        for (int j = 0; j < t.size(); j++) {
            //decrements the count by calculating the ascii value of the letter (A = 0) (B = 1) etc...
            count[t[j] - 'a']--;
            //once the instances of a letter differs between the 2 strings return false
            if (count[t[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};