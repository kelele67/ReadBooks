#include <stack>
//struct TreeNode {
//int val;
//TreeNode *left;
//TreeNode *right;
//TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
//};
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack< const TreeNode* > s;
		//正在访问p，刚刚访问q
		const TreeNode *p = root,*q = nullptr;
		// 因为可能只有一个根结点，所以用do...while更加简洁
		do {
			while (p != nullptr) {//往左下走
				s.push(p);
				p = p->left;
			} 
			// 注意初始化指针
			q = nullptr;
			while (!s.empty()) {
				p = s.top();
				s.pop();
				// 右孩子不存在或者已经被访问过
				if (p->right == q) {
					result.push_back(p->val);
					q = p;
				} else {
					// 当前结点不能访问（因为右子节点还没访问过），重新入栈
					s.push(p);
					// 先处理右子树
					p = p->right;
					break;
				}
			}
		} while (!s.empty());
		return result;
	}
};
