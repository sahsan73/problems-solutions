/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int answer;

    int dfs(TreeNode *root) {
        if(root == nullptr) return 0;

        int lsum = dfs(root->left);
        int rsum = dfs(root->right);
        answer = max(answer, lsum+rsum+root->val);

        // if both children return NEGATIVE sums, we should NOT
        // consider the children's path, and return 0
        // for e.g., [2, -1]
        return max(0, root->val+max(lsum, rsum));
    }

public:
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        dfs(root);
        return answer;
    }
};
