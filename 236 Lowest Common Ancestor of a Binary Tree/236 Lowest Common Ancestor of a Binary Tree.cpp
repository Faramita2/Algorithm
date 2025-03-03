#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return root;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        stack<TreeNode *> s;
        bool              findP = false, findQ = false;
        TreeNode         *prev = nullptr;
        TreeNode         *cur  = root;

        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                s.push(cur);

                if (!findP)
                    s1.push(cur);
                if (!findQ)
                    s2.push(cur);

                if (cur == p)
                    findP = true;

                if (cur == q)
                    findQ = true;

                cur = cur->left;
            }

            cur = s.top();

            if (cur->right == nullptr || cur->right == prev) {
                s.pop();
                if (!findP)
                    s1.pop();
                if (!findQ)
                    s2.pop();
                prev = cur;
                cur  = nullptr;
            } else {
                cur = cur->right;
            }
        }

        while (s1.top() != s2.top()) {
            if (s1.size() > s2.size())
                s1.pop();
            else
                s2.pop();
        }

        return s1.top();
    }

    TreeNode *recrusiveFind(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;
        auto left  = recrusiveFind(root->left, p, q);
        auto right = recrusiveFind(root->right, p, q);
        if (left && right)
            return root;
        return left ? right : left;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    vector<int> nums1 = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    auto        root1 = BinaryTreeUtil::buildTree(nums1);
    BinaryTreeUtil::printTree(root1);
    TreeNode *p1   = BinaryTreeUtil::findNode(root1, 5);
    TreeNode *q1   = BinaryTreeUtil::findNode(root1, 1);
    auto      res1 = solution.lowestCommonAncestor(root1, p1, q1);
    cout << "Lowest common ancestor val is " << res1->val << endl;
    // Output: 3

    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    vector<int> nums2 = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    auto        root2 = BinaryTreeUtil::buildTree(nums2);
    BinaryTreeUtil::printTree(root2);
    TreeNode *p2   = BinaryTreeUtil::findNode(root2, 5);
    TreeNode *q2   = BinaryTreeUtil::findNode(root2, 4);
    auto      res2 = solution.lowestCommonAncestor(root2, p2, q2);
    cout << "Lowest common ancestor val is " << res2->val << endl;
    // Output: 5

    // Input: root = [1,2], p = 1, q = 2
    vector<int> nums3 = {1, 2};
    auto        root3 = BinaryTreeUtil::buildTree(nums3);
    BinaryTreeUtil::printTree(root3);
    TreeNode *p3   = BinaryTreeUtil::findNode(root3, 1);
    TreeNode *q3   = BinaryTreeUtil::findNode(root3, 2);
    auto      res3 = solution.lowestCommonAncestor(root3, p3, q3);
    cout << "Lowest common ancestor val is " << res3->val << endl;
    // Output: 1

    return 0;
}