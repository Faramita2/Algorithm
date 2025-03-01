#include "../BinaryTreeUtil/binary_tree_util.h"
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
    vector<string> res;
    vector<string> path;

  public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == nullptr)
            return res;
        backtracking(root);
        return res;
    }

    void clear()
    {
        res.clear();
    }

  private:
    void backtracking(TreeNode *node)
    {
        path.push_back(to_string(node->val));

        if (node->left == nullptr && node->right == nullptr)
            res.push_back(join(path));

        if (node->left != nullptr)
            backtracking(node->left);

        if (node->right != nullptr)
            backtracking(node->right);

        path.pop_back();
    }

    string join(const vector<string> &strings)
    {
        return accumulate(next(strings.begin()), strings.end(), strings[0],
                          [](const string &a, const string &b) { return a + "->" + b; });
    }
};

int main()
{
    Solution s;

    // Input: root = [1,2,3,null,5]
    vector<int> nums1 = {1, 2, 3, -1, 5};
    TreeNode   *root1 = BinaryTreeUtil::buildTree(nums1);
    BinaryTreeUtil::printTree(root1);
    auto res1 = s.binaryTreePaths(root1);
    for (auto &s : res1) {
        cout << s << " ";
    }
    cout << endl;
    s.clear();
    // Output: ["1->2->5","1->3"]

    // Input: root = [1]
    vector<int> nums2 = {1};
    TreeNode   *root2 = BinaryTreeUtil::buildTree(nums2);
    BinaryTreeUtil::printTree(root2);

    auto res2 = s.binaryTreePaths(root2);
    for (auto &s : res2) {
        cout << s << " ";
    }
    cout << endl;
    // Output: ["1"]

    return 0;
}