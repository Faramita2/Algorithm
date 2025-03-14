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
    int findLengthOfLCIS(vector<int> &nums)
    {
        int         size = nums.size();
        vector<int> dp(size, 1);

        int maxLen = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i]  = dp[i - 1] + 1;
                maxLen = max(maxLen, dp[i]);
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [1,3,5,4,7]
    vector<int> nums1 = {1, 3, 5, 4, 7};
    cout << solution.findLengthOfLCIS(nums1) << endl;
    // Output: 3

    // Input: nums = [2,2,2,2,2]
    vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << solution.findLengthOfLCIS(nums2) << endl;
    // Output: 1

    return 0;
}