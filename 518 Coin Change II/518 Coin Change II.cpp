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
    int change(int amount, vector<int> &coins)
    {
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int j = coin; j < amount + 1; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return dp.back();
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: amount = 5, coins = [1,2,5]
    int         amount1 = 5;
    vector<int> coins1  = {1, 2, 5};
    cout << solution.change(amount1, coins1) << endl;
    // Output: 4

    // Input: amount = 3, coins = [2]
    int         amount2 = 3;
    vector<int> coins2  = {2};
    cout << solution.change(amount2, coins2) << endl;
    // Output: 0

    // Input: amount = 10, coins = [10]
    int         amount3 = 10;
    vector<int> coins3  = {10};
    cout << solution.change(amount3, coins3) << endl;
    // Output: 1

    return 0;
}