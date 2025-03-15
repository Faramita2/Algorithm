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
    int countSubstrings(string s)
    {
        int                  len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        int res = 0;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: s = "abc"
    string s1 = "abc";
    cout << solution.countSubstrings(s1) << endl;
    // Output: 3

    // Input: s = "aaa"
    string s2 = "aaa";
    cout << solution.countSubstrings(s2) << endl;
    // Output: 6

    return 0;
}