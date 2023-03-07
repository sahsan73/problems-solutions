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
    TreeNode *buildTree(int &curr, vector<int> &post, int lo, int hi, unordered_map<int,int> &in) {
        if(lo > hi) return nullptr;

        TreeNode *node = new TreeNode(post[curr--]);
        node->right = buildTree(curr, post, in[node->val]+1, hi, in);
        node->left = buildTree(curr, post, lo, in[node->val]-1, in);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) {
        int n = (int)inorder.size();
        unordered_map<int,int> in;
        for(int i=0; i<n; ++i) in[inorder[i]] = i;

        int curr = n-1;
        return buildTree(curr, post, 0, n-1, in);
    }
};
