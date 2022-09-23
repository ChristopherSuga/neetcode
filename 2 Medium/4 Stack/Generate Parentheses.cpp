/*
    Given n pairs of parentheses, generate all combos of well-formed parentheses
    Ex. n = 3 -> ["((()))","(()())","(())()","()(())","()()()"], n = 1 -> ["()"]

    Backtracking, keep valid, favor trying opens, then try closes if still valid

    Time: O(2^n)
    Space: O(n)
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }
private:
    //helper function that recursively generates the strings.
    void generate(int n, int open, int close, string str, vector<string>& result) {
        //if the count of open and closed parentheses reach the max amount pushes the finished string
        if (open == n && close == n) {
            result.push_back(str);
            return;
        }
        //if there are less open parentheses than the max amount then calls the generate function with an opening parenthesis and increments the open count by 1
        if (open < n) {
            generate(n, open + 1, close, str + '(', result);
        }
        //if there are more open parentheses than the max amount then calls the generate function with a closing parenthesis and increments the close count by 1
        if (open > close) {
            generate(n, open, close + 1, str + ')', result);
        }
    }
};