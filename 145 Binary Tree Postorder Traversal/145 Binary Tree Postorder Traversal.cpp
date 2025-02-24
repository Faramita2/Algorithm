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

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;

		stack<TreeNode*> st;
		TreeNode* last = nullptr;
		TreeNode* p = root;
		while (!st.empty() || p != nullptr) {
			while (p != nullptr) {
				st.push(p);
				last = p;
				p = p->left;
			}

			auto top = st.top();
			if (top->right == nullptr || last == top->right) {
				res.push_back(top->val);
				st.pop();
				last = top;
				p = nullptr;
			}
			else {
				p = top->right;
			}
		}

		return res;
	}

	vector<int> postorderTraversal__(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		stack<TreeNode*> st;
		TreeNode* p = root;
		while (!st.empty() || p != nullptr) {
			if (p != nullptr) {
				res.push_back(p->val);
				st.push(p);
				p = p->right;
			}
			else {
				p = st.top();
				st.pop();
				p = p->left;
			}
		}

		reverse(res.begin(), res.end());
		return res;
	}

	vector<int> postorderTraversal_(TreeNode* root) {
		vector<int> res;
		lrn(root, res);
		return res;
	}

private:
	void lrn(TreeNode* root, vector<int>& res) {
		if (root == nullptr) return;
		if (root->left != nullptr) lrn(root->left, res);
		if (root->right != nullptr) lrn(root->right, res);
		res.push_back(root->val);
	}
};

int main()
{
	auto node1 = new Solution::TreeNode(1);
	auto node2 = new Solution::TreeNode(2);
	auto node3 = new Solution::TreeNode(3);
	node1->right = node2;
	node2->left = node3;

	Solution s;
	vector<int> res = s.postorderTraversal(node1);

	return 0;
}