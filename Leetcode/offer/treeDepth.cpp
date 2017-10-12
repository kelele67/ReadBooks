class Solution {
public:
	int treeDepth(TreeNode *pRoot) {
		if (!pRoot) {
			return 0;
		}
		queue<TreeNode *> q;
		q.push(pRoot);
		int depth = 0;
		while(!que.empty()) {
			int size = queue.size();
			depth++;
			for (int i = 0; i < size; i++) {
				TreeNode *node = q.front();
				que.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		return depth;
	}
};
