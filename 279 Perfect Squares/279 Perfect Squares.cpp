#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int numSquares(int n)
    {
        if (n == 1)
            return 1;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            for (int j = i * i; j <= n; j++) {
                if (dp[j - i * i] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: n = 12
    int n1 = 12;
    cout << solution.numSquares(n1) << endl;
    // Output: 3

    // Input: n = 13
    int n2 = 13;
    cout << solution.numSquares(n2) << endl;
    // Output: 2

    return 0;
}