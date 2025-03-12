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
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;
        for (int coin : coins) {
            for (int j = coin; j < amount + 1; j++) {
                if (dp[j - coin] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: coins = [1,2,5], amount = 11
    vector<int> coins1  = {1, 2, 5};
    int         amount1 = 11;
    cout << solution.coinChange(coins1, amount1) << endl;
    // Output: 3

    // Input: coins = [2], amount = 3
    vector<int> coins2  = {2};
    int         amount2 = 3;
    cout << solution.coinChange(coins2, amount2) << endl;
    // Output: -1

    // Input: coins = [1], amount = 0
    vector<int> coins3  = {1};
    int         amount3 = 0;
    cout << solution.coinChange(coins3, amount3) << endl;
    // Output: 0

    return 0;
}