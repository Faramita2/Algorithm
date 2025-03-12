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
    int maximumCount(vector<int> &nums)
    {
        int p = 0, n = 0;
        for (int num : nums) {
            if (num > 0)
                p++;
            if (num < 0)
                n++;
        }
        return max(p, n);
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [-2,-1,-1,1,2,3]
    vector<int> nums1 = {-2, -1, -1, 1, 2, 3};
    cout << solution.maximumCount(nums1) << endl;
    // Output: 3

    // Input: nums = [-3,-2,-1,0,0,1,2]
    vector<int> nums2 = {-3, -2, -1, 0, 0, 1, 2};
    cout << solution.maximumCount(nums2) << endl;
    // Output: 3;

    // Input: nums = [5,20,66,1314]
    vector<int> nums3 = {5, 20, 66, 1314};
    cout << solution.maximumCount(nums3) << endl;
    // Output: 4

    return 0;
}