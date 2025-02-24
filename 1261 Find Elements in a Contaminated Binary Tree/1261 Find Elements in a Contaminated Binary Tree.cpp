#include <iostream>
#include <unordered_set>
using namespace std;

class FindElements {
public:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
public:
    FindElements(TreeNode* root) { dfs(root, 0); }

    bool find(int target) { return seen.count(target) > 0; }

private:
    unordered_set<int> seen;

    void dfs(TreeNode* currentNode, int currentValue) {
        if (!currentNode) return;
        // visit current node by adding its value to seen
        seen.insert(currentValue);
        dfs(currentNode->left, currentValue * 2 + 1);
        dfs(currentNode->right, currentValue * 2 + 2);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}