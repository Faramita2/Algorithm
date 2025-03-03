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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);

        return root;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [4,2,7,1,3], val = 5
    vector<int> nums1         = {4, 2, 7, 1, 3};
    int         val1          = 5;
    auto        root1         = BinaryTreeUtil::buildTree(nums1);
    auto        insertedRoot1 = solution.insertIntoBST(root1, val1);
    BinaryTreeUtil::printTree(insertedRoot1);
    // Output: [4,2,7,1,3,5]

    // Input: root = [40,20,60,10,30,50,70], val = 25
    vector<int> nums2         = {40, 20, 60, 10, 30, 50, 70};
    int         val2          = 25;
    auto        root2         = BinaryTreeUtil::buildTree(nums2);
    auto        insertedRoot2 = solution.insertIntoBST(root2, val2);
    BinaryTreeUtil::printTree(insertedRoot2);
    // Output: [40,20,60,10,30,50,70,-1,-1,25]

    // Input: root = [4,2,7,1,3,-1,-1,-1,-1,-1,-1], val = 5
    vector<int> nums3         = {4, 2, 7, 1, 3, -1, -1, -1, -1, -1, -1};
    int         val3          = 5;
    auto        root3         = BinaryTreeUtil::buildTree(nums3);
    auto        insertedRoot3 = solution.insertIntoBST(root3, val3);
    BinaryTreeUtil::printTree(insertedRoot3);
    // Output: [4,2,7,1,3,5]

    return 0;
}