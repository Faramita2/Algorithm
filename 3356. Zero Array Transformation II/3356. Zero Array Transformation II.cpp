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
    bool canFormZeroArray(int k, vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();

        vector<long long> diff(n + 1, 0);
        for (int i = 0; i < k; i++) {
            int li   = queries[i][0];
            int ri   = queries[i][1];
            int vali = queries[i][2];
            diff[li] -= vali;
            if (ri + 1 <= n)
                diff[ri + 1] += vali;
        }

        long long current = 0;
        for (int i = 0; i < n; i++) {
            current += diff[i];
            if (nums[i] + current > 0)
                return false;
        }

        return true;
    }

  public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int m = queries.size();

        int left = 0, right = m;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFormZeroArray(mid, nums, queries)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return canFormZeroArray(left, nums, queries) ? left : -1;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = {2,0,2}, queries = {{0,2,1},{0,2,1},{1,1,3}}
    vector<int>         nums1    = {2, 0, 2};
    vector<vector<int>> queries1 = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    cout << solution.minZeroArray(nums1, queries1) << endl;
    // Output: 2

    // Input: nums = {4,3,2,1}, queries = {{1,3,2},{0,2,1}}
    vector<int>         nums2    = {4, 3, 2, 1};
    vector<vector<int>> queries2 = {{1, 3, 2}, {0, 2, 1}};
    cout << solution.minZeroArray(nums2, queries2) << endl;
    // Output: -1

    return 0;
}