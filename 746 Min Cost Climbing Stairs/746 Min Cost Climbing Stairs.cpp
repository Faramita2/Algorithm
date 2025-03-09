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
    int minCostClimbingStairs(vector<int> &cost)
    {
        int         n = cost.size();
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: cost = [10,15,20]
    vector<int> cost1 = {10, 15, 20};
    cout << solution.minCostClimbingStairs(cost1) << endl;
    // Output: 15

    // Input: cost = [1,100,1,1,1,100,1,1,100,1]
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << solution.minCostClimbingStairs(cost2) << endl;
    // Output: 6

    return 0;
}