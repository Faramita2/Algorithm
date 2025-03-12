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
  private:
    int robForLinearNums(vector<int> &nums)
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

  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return max(nums.front(), nums.back());
        vector<int> first = nums, second = nums;
        first.pop_back();
        first.shrink_to_fit();
        second.erase(second.begin(), second.begin() + 1);
        second.shrink_to_fit();

        return max(robForLinearNums(first), robForLinearNums(second));
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [2,3,2]
    vector<int> nums1 = {2, 3, 2};
    cout << solution.rob(nums1) << endl;
    // Output: 3

    // Input: nums = [1,2,3,1]
    vector<int> nums2 = {1, 2, 3, 1};
    cout << solution.rob(nums2) << endl;
    // Output: 4

    vector<int> nums3 = {1, 2, 3};
    cout << solution.rob(nums3) << endl;
    // Output: 3

    return 0;
}