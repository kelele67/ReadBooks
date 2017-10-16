#include <vector>
#include <stack>
#include <iostream>
#include "stdafx.h" 

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<const TreeNode *> s;
		if (root != nullptr) {
			s.push(root);
		}
		if (!s.empty()) {
			const TreeNode *p = s.top();
			s.pop();
			result.push_back(p->val);
			if (p->right != nullptr) {
				s.push(p->right);
			}
			if (p->left != nullptr) {
				s.push(p->left);
			}
		}
		return result;
	}
};


int main() {
	Solution sol;
    // TreeNode a=TreeNode(1);  
    // TreeNode b=TreeNode(2);  
    // TreeNode c=TreeNode(3);  
    // TreeNode d=TreeNode(4);  
    // TreeNode e=TreeNode(5);  
    // a.left=&e;a.right=&b;  
    // b.left=&c;b.right=&d;  
    // e.left=NULL;e.right=NULL;d.left=NULL;d.right=NULL;e.left=NULL;e.right=NULL;
    stack<const TreeNode*> tree = {1, 2, 3};
	vector<int> temp = sol.preorderTraversal(tree);
	int len = temp.size();
	for (int i = 0; i < len; i++) {
		cout << temp[i] << " ";
	}
	cout << "\n" << endl;
	return 1;
}