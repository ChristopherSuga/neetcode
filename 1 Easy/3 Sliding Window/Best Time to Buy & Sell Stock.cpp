/*
    Given array prices, return max profit w/ 1 buy & 1 sell
    Ex. prices = [7,1,5,3,6,4] -> 5 (buy at $1, sell at $6)

    For each, get diff b/w that & min value before, store max

    Time: O(n)
    Space: O(1)
*/
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        //initializes the minimum price as the value for the first day
        int lowestPrice = prices[0];
        int maxProfit = 0;
        //starts looping from the second day because cannot sell on first day
        for (int i = 1; i < prices.size(); i++)
        {
            //compares the current number to the previous lowest price. updates the lowest price of the two
            lowestPrice = min(lowestPrice, prices[i]);
            //calculates the potential price difference between todays price and the previous lowest price. Compares this number to the currect max profit and updates the larger of the two
            maxProfit = max(maxProfit, prices[i] - lowestPrice);
        }
        return maxProfit;
    }
};