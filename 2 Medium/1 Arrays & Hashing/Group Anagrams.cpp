/*
	Given array of strings, group anagrams together (same letters diff order)
	Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

	Count chars, for each string use total char counts (naturally sorted) as key

	Time: O(n x l) -> n = length of strs, l = max length of a string in strs
	Space: O(n x l)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //creates an unordered map of 
        unordered_map<string, vector<string>> mp;
        //loops over the vector
        for (string s : strs) {
            string temp = s;
            //sorts the string
            sort(temp.begin(), temp.end());
            //pushes the string to the temp key
            mp[temp].push_back(s);
        }
        //creates a vector 
        vector<vector<string>> anagrams;
        //loops through the map
        for (auto p : mp) {
            //pushes back the second value of p which is the mapped value
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};