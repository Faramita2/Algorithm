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
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
            return nums.front();
        if (size == 2)
            return max(nums.front(), nums.back());
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [1,2,3,1]
    vector<int> nums1 = {1, 2, 3, 1};
    cout << solution.rob(nums1) << endl;
    // Output: 4

    // Input: nums = [2,7,9,3,1]
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << solution.rob(nums2) << endl;
    // Output: 12

    return 0;
}