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
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int                 size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        int maximum = 0;
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                maximum = max(dp[i][j], maximum);
            }
        }

        return maximum;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums1 = [1,4,2], nums2 = [1,2,4]
    vector<int> nums1 = {1, 4, 2}, nums2 = {1, 2, 4};
    cout << solution.maxUncrossedLines(nums1, nums2) << endl;
    // Output: 2

    // Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
    vector<int> nums3 = {2, 5, 1, 2, 5}, nums4 = {10, 5, 2, 1, 5, 2};
    cout << solution.maxUncrossedLines(nums3, nums4) << endl;
    // Output: 3

    // Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
    vector<int> nums5 = {1, 3, 7, 1, 7, 5}, nums6 = {1, 9, 2, 5, 1};
    cout << solution.maxUncrossedLines(nums5, nums6) << endl;
    // Output: 2

    return 0;
}