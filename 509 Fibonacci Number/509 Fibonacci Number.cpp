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
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
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
    cout << solution.fib(n1) << endl;
    // Output: 1

    // Input: n = 3
    int n2 = 3;
    cout << solution.fib(n2) << endl;
    // Output: 2

    // Input: n = 4
    int n3 = 4;
    cout << solution.fib(n3) << endl;
    // Output: 3

    return 0;
}