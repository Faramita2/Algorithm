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
    TreeNode *convertBST(TreeNode *root)
    {
        int curSum = 0;
        rnl(root, curSum);
        return root;
    }

  private:
    void rnl(TreeNode *root, int &curSum)
    {
        if (root == nullptr)
            return;
        rnl(root->right, curSum);
        curSum += root->val;
        root->val = curSum;
        rnl(root->left, curSum);
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8]
    vector<int> nums1          = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
    auto        root1          = BinaryTreeUtil::buildTree(nums1);
    auto        convertedRoot1 = solution.convertBST(root1);
    BinaryTreeUtil::printTree(convertedRoot1);
    // Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

    // Input: root = [0,null,1]
    vector<int> nums2          = {0, -1, 1};
    auto        root2          = BinaryTreeUtil::buildTree(nums2);
    auto        convertedRoot2 = solution.convertBST(root2);
    BinaryTreeUtil::printTree(convertedRoot2);
    // Output: [1,null,1]

    return 0;
}