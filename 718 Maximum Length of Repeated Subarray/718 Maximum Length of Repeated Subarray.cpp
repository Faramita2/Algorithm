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
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int                 m = nums1.size(), n = nums2.size();
        int                 maxLen = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLen   = max(maxLen, dp[i][j]);
                }
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
    vector<int> nums1 = {1, 2, 3, 2, 1}, nums2 = {3, 2, 1, 4, 7};
    cout << solution.findLength(nums1, nums2) << endl;
    // Output: 3

    // Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
    vector<int> nums3 = {0, 0, 0, 0, 0}, nums4 = {0, 0, 0, 0, 0};
    cout << solution.findLength(nums3, nums4) << endl;
    // Output: 5

    return 0;
}