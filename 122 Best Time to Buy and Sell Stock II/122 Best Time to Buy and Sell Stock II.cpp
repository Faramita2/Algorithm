#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;
        vector<pair<int, int>> dp(prices.size(), {0, 0});
        // first: hold, second: unhold
        dp[0].first = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            // keep "hold" state like previous or buy a new stock when previous is "unhold"
            int hold = max(dp[i - 1].first, dp[i - 1].second - prices[i]);
            // keep "unhold" state like previous or sell the previous stock to be "unhold"
            int unhold = max(dp[i - 1].second, dp[i - 1].first + prices[i]);
            dp[i]      = {hold, unhold};
        }
        return dp.back().second;
    }

    int maxProfit_(vector<int> &prices)
    {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: prices = [7,1,5,3,6,4]
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(prices1) << endl;
    // Output: 7

    // Input: prices = [1,2,3,4,5]
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << solution.maxProfit(prices2) << endl;
    // Output: 4

    // Input: prices = [7,6,4,3,1]
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(prices3) << endl;
    // Output: 0

    return 0;
}