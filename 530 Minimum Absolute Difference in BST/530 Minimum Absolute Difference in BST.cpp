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
    int getMinimumDifference(TreeNode *root)
    {
        int minD     = INT_MAX;
        int preValue = -1;
        lnr(root, minD, preValue);
        return minD;
    }

  private:
    void lnr(TreeNode *node, int &minD, int &preValue)
    {
        if (node == nullptr)
            return;

        lnr(node->left, minD, preValue);

        if (preValue != -1)
            minD = min(node->val - preValue, minD);

        preValue = node->val;
        lnr(node->right, minD, preValue);
    }
};

int main()
{

    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [4,2,6,1,3]
    vector<int> nums1 = {5, 4, 7};
    auto        root1 = BinaryTreeUtil::buildTree(nums1);
    BinaryTreeUtil::printTree(root1);
    assert(1 == solution.getMinimumDifference(root1));
    // Output: 1

    // Input: root = [1,0,48,null,null,12,49]
    vector<int> nums2 = {1, 0, 48, -1, -1, 12, 49};
    auto        root2 = BinaryTreeUtil::buildTree(nums2);
    BinaryTreeUtil::printTree(root2);
    assert(1 == solution.getMinimumDifference(root2));
    // Output: 1

    return 0;
}