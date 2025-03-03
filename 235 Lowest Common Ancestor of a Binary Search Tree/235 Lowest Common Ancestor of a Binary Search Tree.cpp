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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val > q->val)
            swap(q, p);

        while (root != nullptr) {
            if (p->val <= root->val && root->val <= q->val)
                return root;
            else if (q->val < root->val)
                root = root->left;
            else {
                root = root->right;
            }
        }

        return nullptr;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    vector<int> nums1 = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    auto        root1 = BinaryTreeUtil::buildTree(nums1);
    BinaryTreeUtil::printTree(root1);
    TreeNode *p1   = BinaryTreeUtil::findNode(root1, 2);
    TreeNode *q1   = BinaryTreeUtil::findNode(root1, 8);
    auto      res1 = solution.lowestCommonAncestor(root1, p1, q1);
    cout << "Lowest common ancestor val is " << res1->val << endl;
    // Output: 6

    // Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    vector<int> nums2 = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    auto        root2 = BinaryTreeUtil::buildTree(nums2);
    BinaryTreeUtil::printTree(root2);
    TreeNode *p2   = BinaryTreeUtil::findNode(root2, 2);
    TreeNode *q2   = BinaryTreeUtil::findNode(root2, 4);
    auto      res2 = solution.lowestCommonAncestor(root2, p2, q2);
    cout << "Lowest common ancestor val is " << res2->val << endl;
    // Output: 2

    // Input: root = [2,1], p = 2, q = 1
    vector<int> nums3 = {2, 1};
    auto        root3 = BinaryTreeUtil::buildTree(nums3);
    BinaryTreeUtil::printTree(root3);
    TreeNode *p3   = BinaryTreeUtil::findNode(root3, 2);
    TreeNode *q3   = BinaryTreeUtil::findNode(root3, 1);
    auto      res3 = solution.lowestCommonAncestor(root3, p3, q3);
    cout << "Lowest common ancestor val is " << res3->val << endl;
    // Output: 2

    return 0;
}