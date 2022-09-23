/*
    Given array of temps, return an array w/ # of days until warmer
    Ex. temperature = [73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]

    Monotonic decr stack, at each day, compare incr from prev days

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        // pair: [index, temp]
        stack<pair<int, int>> stk;
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int currDay = i;
            int currTemp = temperatures[i];

            //while the temperature of the top of the stack is less than the temperature for the current day
            while (!stk.empty() && stk.top().second < currTemp) {
                //saves the value of the previous day
                int prevDay = stk.top().first;
                //pops the previous day
                stk.pop();
                //sets the index of the previous day to the current day - the previous day
                result[prevDay] = currDay - prevDay;
            }
            //pushes the current day and the current temp as a pair to the stack
            stk.push({ currDay, currTemp });
        }
        return result;
    }
};