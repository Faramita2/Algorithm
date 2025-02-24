#include <iostream>
#include<queue>
using namespace std;

class Solution {
public:
	class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node* next;

		Node() : val(0), left(NULL), right(NULL), next(NULL) {}

		Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

		Node(int _val, Node* _left, Node* _right, Node* _next)
			: val(_val), left(_left), right(_right), next(_next) {
		}
	};

	Node* connect__(Node* root) {
		Node* prev = root, * curr;
		while (prev != nullptr) {
			curr = prev;
			while (curr != nullptr && curr->left != nullptr) {
				curr->left->next = curr->right;
				if (curr->next != nullptr) curr->right->next = curr->next->left;
				curr = curr->next;
			}
			prev = prev->left;
		}
		return root;
	}

	Node* connect_(Node* root) {
		if (root == nullptr) return root;
		if (root->left != nullptr) root->left->next = root->right;
		if (root->right != nullptr && root->next != nullptr) root->right->next = root->next->left;

		connect(root->left);
		connect(root->right);

		return root;
	}

	Node* connect(Node* root) {
		if (root == nullptr) return root;
		Node* dummy = new Node();
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* pre = dummy;
			int size = q.size();
			while (--size >= 0) {
				auto front = q.front();
				q.pop();
				pre->next = front;
				pre = front;
				if (front->left != nullptr) q.push(front->left);
				if (front->right != nullptr) q.push(front->right);
			}
			dummy->next = nullptr;
			pre->next = nullptr;
		}
		delete dummy;
		return root;
	}
};
int main()
{
	std::cout << "Hello World!\n";
}