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
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 1; i <= n; i++) {
            if (i < 3)
                continue;
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: n = 2
    int n1 = 2;
    cout << solution.climbStairs(n1) << endl;
    // Output: 2

    // Input: n = 3
    int n2 = 3;
    cout << solution.climbStairs(n2) << endl;
    // Output: 3

    return 0;
}