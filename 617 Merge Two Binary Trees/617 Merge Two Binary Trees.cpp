#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 != nullptr && root2 != nullptr) {
            root1->val += root2->val;
            root1->left  = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        }

        return root1 == nullptr ? root2 : root1;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
    auto root1 = BinaryTreeUtil::buildTree({1, 3, 2, 5});
    BinaryTreeUtil::printTree(root1);
    auto root2 = BinaryTreeUtil::buildTree({2, 1, 3, -1, 4, -1, 7});
    BinaryTreeUtil::printTree(root2);

    monitor.start();
    auto merged1 = solution.mergeTrees(root1, root2);
    monitor.stop();
    BinaryTreeUtil::printTree(merged1);
    // Output: [3,4,5,5,4,null,7]

    // Input: root1 = [1], root2 = [1,2]
    auto root3 = BinaryTreeUtil::buildTree({1});
    BinaryTreeUtil::printTree(root3);
    auto root4 = BinaryTreeUtil::buildTree({1, 2});
    BinaryTreeUtil::printTree(root4);

    monitor.start();
    auto merged2 = solution.mergeTrees(root3, root4);
    monitor.stop();
    BinaryTreeUtil::printTree(merged2);
    // Output: [2,2]

    return 0;
}