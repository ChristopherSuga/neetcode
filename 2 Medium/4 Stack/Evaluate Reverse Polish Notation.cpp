/*
    Evaluate RPN, valid operators: +, -, *, /

    Stack, if num push, if operator apply to top 2 nums

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        //iterates over the vector of strings
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            //if the token is greater than 2 char then it is automatically a number and added or if token is a single digit then it gets added to the stack and continues the loop
            if (token.size() > 1 || isdigit(token[0])) {
                stk.push(stoi(token));
                continue;
            }
            //if the token is not a digit then it takes the top 2 numbers and does the operation
            auto num2 = stk.top();
            stk.pop();
            auto num1 = stk.top();
            stk.pop();

            auto result = 0;
            //stores the result depending on what the token is
            if (token == "+") {
                result = num1 + num2;
            }
            else if (token == "-") {
                result = num1 - num2;
            }
            else if (token == "*") {
                result = num1 * num2;
            }
            else {
                result = num1 / num2;
            }
            stk.push(result);
        }

        return stk.top();
    }
};