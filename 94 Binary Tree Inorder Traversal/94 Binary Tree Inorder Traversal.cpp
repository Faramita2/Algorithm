#include <iostream>
#include <stack>
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

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		stack<TreeNode*> st;
		TreeNode* p = root;
		while (p != nullptr || !st.empty()) {
			while (p != nullptr) {
				st.push(p);
				p = p->left;
			}
			res.push_back(st.top()->val);
			p = st.top()->right;
			st.pop();
		}

		return res;
	}

	vector<int> inorderTraversal_(TreeNode* root) {
		vector<int> res;
		lnr(root, res);
		return res;
	}
private:
	void lnr(TreeNode* root, vector<int>& res) {
		if (root == nullptr) return;
		if (root->left != nullptr) lnr(root->left, res);
		res.push_back(root->val);
		if (root->right != nullptr) lnr(root->right, res);
	}
};

int main()
{
	std::cout << "Hello World!\n";
}