#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    TreeNode *pre;

  public:
    bool isValidBST(TreeNode *root)
    {
        if (root != nullptr) {
            if (!isValidBST(root->left))
                return false;
            if (pre != nullptr && pre->val >= root->val)
                return false;
            pre = root;
            if (!isValidBST(root->right))
                return false;
        }
        return true;
    }
};

int main()
{

    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [2,1,3]
    vector<int> nums1 = {2, 1, 3};
    auto        root1 = BinaryTreeUtil::buildTree(nums1);
    assert(true == solution.isValidBST(root1));
    // Output: true;

    // Input: root = [5,1,4,null,null,3,6]
    vector<int> nums2 = {5, 1, 4, -1, -1, 3, 6};
    auto        root2 = BinaryTreeUtil::buildTree(nums2);
    assert(false == solution.isValidBST(root2));
    // Output: false;

    return 0;
}