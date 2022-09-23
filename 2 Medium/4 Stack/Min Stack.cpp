/*
    Design stack that supports push, pop, top, & retriving min element

    2 stacks, 1 normal & 1 monotonic decr, only push if lower than top

    Time: O(1)
    Space: O(n)
*/

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        stk.push(val);

        //if the minstack is empty or the value being added is smaller than the min then pushes the new value as the smallest 
        if (minStk.empty() || val < minStk.top().first) {
            minStk.push({ val, 1 });
        }
        //if the value is equal to the min the count of that value is added but the value itself is not pushed
        else if (val == minStk.top().first) {
            minStk.top().second++;
        }
    }

    void pop() {
        //if the top of both stacks are equal then the count gets decremented
        if (stk.top() == minStk.top().first) {
            minStk.top().second--;
            //if the count is 0 then it is popped
            if (minStk.top().second == 0) {
                minStk.pop();
            }
        }
        //pops from the main stack
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top().first;
    }
private:
    stack<int> stk;
    stack<pair<int, int>> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */