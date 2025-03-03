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
    vector<int> findMode(TreeNode *root)
    {
        vector<int> res;
        int         maxFreq = 0, curFreq = 0;
        int         prev = INT_MIN;

        lnr(root, res, maxFreq, curFreq, prev);

        return res;
    }

  private:
    void lnr(TreeNode *node, vector<int> &res, int &maxFreq, int &curFreq, int &prev)
    {
        if (node == nullptr)
            return;

        lnr(node->left, res, maxFreq, curFreq, prev);

        if (node->val == prev)
            curFreq++;
        else {
            curFreq = 1;
            prev    = node->val;
        }

        if (curFreq > maxFreq) {
            maxFreq = curFreq;
            res.clear();
            res.push_back(node->val);
        } else if (curFreq == maxFreq) {
            res.push_back(node->val);
        }

        lnr(node->right, res, maxFreq, curFreq, prev);
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [1,null,2,2]
    vector<int> nums1 = {1, -1, 2, 2};
    auto        root1 = BinaryTreeUtil::buildTree(nums1);
    // BinaryTreeUtil::printTree(root1);
    auto res1 = solution.findMode(root1);
    for (int i : res1) {
        cout << i << " ";
    }
    cout << endl;
    // Output : 2

    // Input: root = [0]
    vector<int> nums2 = {0};
    auto        root2 = BinaryTreeUtil::buildTree(nums2);
    // BinaryTreeUtil::printTree(root2);
    auto res2 = solution.findMode(root2);
    for (int i : res2) {
        cout << i << " ";
    }
    cout << endl;
    // Output : 0

    return 0;
}