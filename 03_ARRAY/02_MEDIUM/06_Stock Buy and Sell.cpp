// 🔹 Problem: Best Time to Buy and Sell Stock (LeetCode 121)
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*  
Approach: Single Pass (Optimal)  
- Keep track of the minimum price so far.  
- At each step, calculate profit = currentPrice - minPrice.  
- Update maximum profit if this profit is larger.  
- Update minPrice when a smaller price is found.  

Time Complexity: O(n)  
Space Complexity: O(1)  
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            int cost = prices[i] - mini;   // potential profit if sold today
            profit = max(cost, profit);    // update max profit
            mini = min(mini, prices[i]);   // update min price
        }
        return profit;
    }
};
