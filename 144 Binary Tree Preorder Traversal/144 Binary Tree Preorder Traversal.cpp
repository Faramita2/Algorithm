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

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;

		stack<TreeNode*> st;
		st.push(root);

		TreeNode* p;
		while (!st.empty()) {
			p = st.top();
			st.pop();
			if (p == nullptr) continue;
			res.push_back(p->val);

			if (p->right != nullptr) st.push(p->right);
			if (p->left != nullptr) st.push(p->left);
		}

		return res;
	}

	vector<int> preorderTraversal_(TreeNode* root) {
		vector<int> res;
		nlr(root, res);
		return res;
	}

private:
	void nlr(TreeNode* root, vector<int>& res) {
		if (root == nullptr) return;
		res.push_back(root->val);
		if (root->left != nullptr) nlr(root->left, res);
		if (root->right != nullptr) nlr(root->right, res);
	}
};

int main()
{
	std::cout << "Hello World!\n";
}