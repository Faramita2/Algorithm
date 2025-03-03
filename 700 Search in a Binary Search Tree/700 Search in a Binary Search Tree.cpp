#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr) {
            return root;
        }

        if (val == root->val)
            return root;
        else if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};

int main()
{

    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [4,2,7,1,3], val = 2
    vector<int> nums1 = {4, 2, 7, 1, 3};
    int         val1  = 2;
    auto        root1 = BinaryTreeUtil::buildTree(nums1);
    monitor.start();
    auto res1 = solution.searchBST(root1, val1);
    monitor.stop();
    BinaryTreeUtil::printTree(res1);
    // Output: [2,1,3]

    // Input: root = [4,2,7,1,3], val = 5
    vector<int> nums2 = {4, 2, 7, 1, 3};
    int         val2  = 5;
    auto        root2 = BinaryTreeUtil::buildTree(nums2);
    monitor.start();
    auto res2 = solution.searchBST(root2, val2);
    monitor.stop();
    BinaryTreeUtil::printTree(res2);
    // Output: []

    return 0;
}