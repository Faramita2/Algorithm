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
    unordered_map<TreeNode *, pair<int, int>> m;

  private:
    pair<int, int> lrn(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};

        if (m.count(root)) {
            return m[root];
        }

        auto ldp = lrn(root->left);
        auto rdp = lrn(root->right);

        int notRob = max(ldp.first, ldp.second) + max(rdp.first, rdp.second);
        int rob    = root->val + ldp.first + rdp.first;

        m[root] = {notRob, rob};

        return m[root];
    }

  public:
    int rob(TreeNode *root)
    {
        auto res = lrn(root);
        return max(res.first, res.second);
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [3,2,3,-1,3,-1,1]
    vector<int> nums1 = {3, 2, 3, -1, 3, -1, 1};
    TreeNode   *root1 = BinaryTreeUtil::buildTree(nums1);
    cout << solution.rob(root1) << endl;
    // Output: 7

    // Input: root = [3,4,5,1,3,-1,1]
    vector<int> nums2 = {3, 4, 5, 1, 3, -1, 1};
    TreeNode   *root2 = BinaryTreeUtil::buildTree(nums2);
    cout << solution.rob(root2) << endl;
    // Output: 9

    return 0;
}