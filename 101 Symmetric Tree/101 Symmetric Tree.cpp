#include <iostream>
#include <vector>
#include <stack>
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

	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		stack<TreeNode*> st;
		st.push(root->left);
		st.push(root->right);

		while (!st.empty()) {
			auto left = st.top();
			st.pop();
			auto right = st.top();
			st.pop();
			if (left == nullptr && right == nullptr) continue;
			if (left == nullptr || right == nullptr) return false;
			st.push(left->left);
			st.push(right->right);
			st.push(left->right);
			st.push(right->left);
		}

		return true;
	}

	bool isSymmetric__(TreeNode* root) {
		if (root == nullptr) return true;
		vector<TreeNode*> children;
		children.push_back(root);
		while (!children.empty()) {
			int size = children.size();
			for (int i = 0; i < size; i++) {
				if (children[i] == nullptr && children[size - i - 1] == nullptr) {
					continue;
				}
				else if ((children[i] == nullptr) || (children[size - i - 1] == nullptr)) {
					return false;
				}
				else if (children[i]->val != children[size - i - 1]->val)
					return false;
				else {
					children.push_back(children[i]->left);
					children.push_back(children[i]->right);
				}
			}
			children.erase(children.begin(), children.begin() + size);
			children.shrink_to_fit();
		}
		return true;
	}

	bool isSymmetric_(TreeNode* root) {
		if (root == nullptr) return true;
		return check(root->left, root->right);
	}

private:
	bool check(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) return true;
		if (left == nullptr || right == nullptr) return false;
		if (left->val != right->val) return false;

		return check(left->left, right->right) && check(left->right, right->left);
	}
};

int main()
{
	auto root = new Solution::TreeNode(1);

	auto node1 = new Solution::TreeNode(2);
	auto node2 = new Solution::TreeNode(2);

	auto node3 = new Solution::TreeNode(3);
	auto node4 = new Solution::TreeNode(4);
	auto node5 = new Solution::TreeNode(4);
	auto node6 = new Solution::TreeNode(3);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;
	node2->left = node5;
	node2->right = node6;

	Solution s;
	auto res = s.isSymmetric(root);

	return 0;
}