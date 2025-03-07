#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  private:
    void backtracking(int startIndex, vector<int> &nums, int lastFlag, vector<int> &path,
                      size_t &maxLen)
    {
        maxLen = max(path.size(), maxLen);

        if (nums.size() == startIndex)
            return;

        for (int i = startIndex; i < nums.size(); i++) {
            int flag;
            if (path.empty()) {
                flag = 0;
            } else {
                flag = nums[i] == path.back()
                           ? 0
                           : (nums[i] - path.back()) / abs(nums[i] - path.back());
                if (flag == lastFlag || nums[i] == path.back())
                    continue;
            }

            path.push_back(nums[i]);
            backtracking(i + 1, nums, flag, path, maxLen);
            path.pop_back();
        }
    }

  public:
    int wiggleMaxLength_(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        if (nums.size() == 2)
            return nums[0] != nums[1] ? 2 : 1;

        size_t      maxLen = 0;
        vector<int> path;

        backtracking(0, nums, 0, path, maxLen);

        return maxLen;
    }

    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int res     = 1;
        int preDiff = 0, curDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff <= 0 & curDiff > 0) || (preDiff >= 0 & curDiff < 0)) {
                res++;
                preDiff = curDiff;
            }
        }

        return res;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [1,7,4,9,2,5]
    vector<int> nums1 = {1, 7, 4, 9, 2, 5};
    cout << solution.wiggleMaxLength(nums1) << endl;
    // Output: 6

    // Input: nums = [1,17,5,10,13,15,10,5,16,8]
    vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << solution.wiggleMaxLength(nums2) << endl;
    // Output: 7

    // Input: nums = [1,2,3,4,5,6,7,8,9]
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << solution.wiggleMaxLength(nums3) << endl;
    // Output: 2

    return 0;
}