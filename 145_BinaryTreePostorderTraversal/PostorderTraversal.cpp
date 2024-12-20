class Solution {
public:
	vector<int> result;
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root) return result;
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		result.push_back(root->val);
		return result;
	}
};