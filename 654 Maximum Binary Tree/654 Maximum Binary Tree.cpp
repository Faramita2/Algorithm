#include "../BinaryTreeUtil/binary_tree_util.h"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> nums;

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        this->nums = nums;
        return buildTree(0, nums.size());
    }

  private:
    pair<int, int> getMaxValue(int start, int end)
    {
        int maxValue = nums[start];
        int maxIndex = start;
        for (int i = start + 1; i < end; ++i) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxIndex = i;
            }
        }
        return {maxValue, maxIndex};
    }

    TreeNode *buildTree(int start, int end)
    {
        if (end == start)
            return nullptr;

        auto [maxValue, mid] = getMaxValue(start, end);
        TreeNode *root       = new TreeNode(maxValue);
        if (end - start == 1)
            return root;

        root->left  = buildTree(start, mid);
        root->right = buildTree(mid + 1, end);

        return root;
    }
};

int main()
{
    Solution s;
    // Input: nums = [3,2,1,6,0,5]
    vector<int> nums1 = {3, 2, 1, 6, 0, 5};
    TreeNode   *root1 = s.constructMaximumBinaryTree(nums1);
    BinaryTreeUtil::printTree(root1);
    // Output: [6,3,5,null,2,0,null,null,1]

    // Input: nums = [3,2,1]
    vector<int> nums2 = {3, 2, 1};
    TreeNode   *root2 = s.constructMaximumBinaryTree(nums2);
    BinaryTreeUtil::printTree(root2);
    // Output: [3,null,2,null,1]

    return 0;
}