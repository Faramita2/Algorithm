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
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i < 2 * k + 1; i++) {
            if (i % 2 == 1)
                dp[0][i] = -prices[0];
        }

        for (int i = 1; i < prices.size(); i++) {
            auto        prev = dp[i - 1];
            vector<int> tmp(2 * k + 1, 0);
            int         price = prices[i];
            for (int j = 1; j < 2 * k + 1; j++) {
                // hold
                if (j % 2 == 1)
                    tmp[j] = max(prev[j], prev[j - 1] - price);
                // unhold
                else
                    tmp[j] = max(prev[j], prev[j - 1] + price);
            }
            dp[i] = tmp;
        }

        int  res  = 0;
        auto back = dp.back();
        for (int i = 0; i < 2 * k + 1; i += 2) {
            res = max(res, back[i]);
        }
        return res;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: k = 2, prices = [2,4,1]
    int         k1      = 2;
    vector<int> prices1 = {2, 4, 1};
    cout << solution.maxProfit(k1, prices1) << endl;
    // Output: 2

    // Input: k = 2, prices = [3,2,6,5,0,3]
    int         k2      = 2;
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    cout << solution.maxProfit(k2, prices2) << endl;
    // Output: 7

    return 0;
}