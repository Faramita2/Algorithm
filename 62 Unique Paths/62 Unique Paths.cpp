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
    int uniquePaths(int m, int n)
    {
        if (m < 2 || n < 2)
            return 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][1] = 1;
        dp[1][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: m = 3, n = 7
    int m1 = 3, n1 = 7;
    cout << solution.uniquePaths(m1, n1) << endl;
    // Output: 28

    // Input: m = 3, n = 2
    int m2 = 3, n2 = 2;
    cout << solution.uniquePaths(m2, n2) << endl;
    // Output: 3

    // Input: m = 1, n = 2
    int m3 = 1, n3 = 2;
    cout << solution.uniquePaths(m3, n3) << endl;
    // Output: 2

    return 0;
}