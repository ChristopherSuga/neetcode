/*
    Given s w/ '(, ), {, }, [, ]', determine if valid
    Ex. s = "()[]{}" -> true, s = "(]" -> false

    Stack of opens, check for matching closes & validity

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        //loops over the string given
        for (int i = 0; i < s.size(); i++) {
            //enters if the char we are looking at is a closing type 
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                //if the current char is a closing type but there is nothing in the stack automatically means there is no opening type
                if (open.empty()) {
                    return false;
                }
                //if the closing type does not correspond to the open type returns false
                if (s[i] == ')' && open.top() != '(') {
                    return false;
                }
                if (s[i] == '}' && open.top() != '{') {
                    return false;
                }
                if (s[i] == ']' && open.top() != '[') {
                    return false;
                }
                //if they do match then the open type gets popped
                open.pop();
            }
            //if the char is not a closing type then the char is added to the stack
            else {
                open.push(s[i]);
            }
        }
        //if by the end of the loop there are still leftover items in the stack then they were never properly closed
        if (!open.empty()) {
            return false;
        }
        return true;
    }
};