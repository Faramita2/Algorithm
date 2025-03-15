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
    int minDistance(string word1, string word2)
    {
        int                 len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 0; i < len1 + 1; i++)
            dp[i][0] = i;
        for (int j = 0; j < len2 + 1; j++)
            dp[0][j] = j;

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
                }
            }
        }
        return dp[len1][len2];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: word1 = "horse", word2 = "ros"
    string word1 = "horse", word2 = "ros";
    cout << solution.minDistance(word1, word2) << endl;
    // Output: 3

    // Input: word1 = "intention", word2 = "execution"
    string word3 = "intention", word4 = "execution";
    cout << solution.minDistance(word3, word4) << endl;
    // Output: 5

    return 0;
}