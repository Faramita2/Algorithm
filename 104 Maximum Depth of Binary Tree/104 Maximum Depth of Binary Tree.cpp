#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};

	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);
		return max(left_depth, right_depth) + 1;
	}

	int maxDepth(TreeNode* root) {
		int max_depth = 0;
		depthHelper(root, 1, max_depth);
		return max_depth;
	}

private:
	void depthHelper(TreeNode* root, int current_depth, int& max_depth) {
		if (root == nullptr) return;

		if (root->left == nullptr && root->right == nullptr) {
			max_depth = max(current_depth, max_depth);
		}

		depthHelper(root->left, current_depth + 1, max_depth);
		depthHelper(root->right, current_depth + 1, max_depth);
	}
};

int main()
{
	std::cout << "Hello World!\n";
}