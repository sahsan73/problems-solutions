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
public:
    TreeNode *buildTree(int &curr, vector<int> &pre, int lo, int hi, unordered_map<int,int> &in) {
        if(lo > hi) return nullptr;

        TreeNode *node = new TreeNode(pre[curr++]);
        node->left = buildTree(curr, pre, lo, in[node->val]-1, in);
        node->right = buildTree(curr, pre, in[node->val]+1, hi, in);

        return node;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& inorder) {
        int n = (int)pre.size();
        unordered_map<int, int> in;
        for(int i=0; i<n; ++i) in[inorder[i]] = i;

        int curr = 0;
        return buildTree(curr, pre, 0, n-1, in);
    }
};
