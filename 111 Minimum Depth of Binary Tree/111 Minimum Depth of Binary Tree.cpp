#include <iostream>
#include <vector>
#include <queue>
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

	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		queue<pair<TreeNode*, int>> q;
		q.push({ root, 1 });
		while (!q.empty()) {
			auto [p, depth] = q.front();
			q.pop();
			if (p->left == nullptr && p->right == nullptr)
				return depth;
			if (p->left != nullptr)
				q.push({ p->left, depth + 1 });
			if (p->right != nullptr)
				q.push({ p->right, depth + 1 });
		}
		return 0;
	}

	int minDepth_(TreeNode* root) {
		if (root == nullptr) return 0;

		int depth = 1;
		int minDepth = INT_MAX;
		getDepth(root, depth, minDepth);

		return minDepth;
	}

private:
	void getDepth(TreeNode* root, int depth, int& minDepth) {
		if (root->left == nullptr && root->right == nullptr) minDepth = min(depth, minDepth);
		if (root->left != nullptr) getDepth(root->left, depth + 1, minDepth);
		if (root->right != nullptr) getDepth(root->right, depth + 1, minDepth);
	}
};

int main()
{
	std::cout << "Hello World!\n";
}