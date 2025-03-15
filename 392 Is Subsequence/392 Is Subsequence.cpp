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
    bool isSubsequence(string s, string t)
    {
        if (s.empty())
            return true;
        int                 len1 = s.length(), len2 = t.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];
                if (dp[i][j] == len1)
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: s = "abc", t = "ahbgdc"
    string s1 = "abc", t1 = "ahbgdc";
    cout << solution.isSubsequence(s1, t1) << endl;
    // Output: true

    // Input: s = "axc", t = "ahbgdc"
    string s2 = "axc", t2 = "ahbgdc";
    cout << solution.isSubsequence(s2, t2) << endl;
    // Output: false;

    return 0;
}