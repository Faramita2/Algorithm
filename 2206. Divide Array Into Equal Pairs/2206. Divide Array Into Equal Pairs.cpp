#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool divideArray(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;

        for (auto &p : m) {
            if (p.second % 2 == 1)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [3,2,3,2,2,2]
    vector<int> nums1 = {3, 2, 3, 2, 2, 2};
    cout << solution.divideArray(nums1) << endl;
    // Output: true;

    // Input: nums = [1,2,3,4]
    vector<int> nums2 = {1, 2, 3, 4};
    cout << solution.divideArray(nums2) << endl;
    // Output: false

    return 0;
}