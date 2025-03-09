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
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i < n + 1; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }

        for (int i : dp) {
            cout << i << " ";
        }
        cout << endl;

        return dp[n];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: n = 2
    int n1 = 2;
    cout << solution.integerBreak(n1) << endl;
    // Output: 1

    // Input: n = 10
    int n2 = 10;
    cout << solution.integerBreak(n2) << endl;
    // Output: 36

    return 0;
}