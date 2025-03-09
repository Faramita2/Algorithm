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
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: n = 3
    int n1 = 3;
    cout << solution.numTrees(n1) << endl;
    // Output: 5

    int n2 = 1;
    cout << solution.numTrees(n2) << endl;
    // Output: 1

    return 0;
}