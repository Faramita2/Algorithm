#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
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

        for (int i = 1; i < dp.size(); i++) {
            int hold   = max(-prices[i], dp[i - 1].first);
            int unhold = max(prices[i] + dp[i - 1].first, dp[i - 1].second);
            dp[i]      = {hold, unhold};
        }

        return dp.back().second;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: prices = [7,1,5,3,6,4]
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(prices1) << endl;
    // Output: 5

    // Input: prices = [7,6,4,3,1]
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(prices2) << endl;
    // Output: 0

    return 0;
}