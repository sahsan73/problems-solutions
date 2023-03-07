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
    TreeNode *constructBST(int lo, int hi, vector<int> &nums) {
        if(lo > hi) return nullptr;
        
        int mid = (lo + hi) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = constructBST(lo, mid-1, nums);
        node->right = constructBST(mid+1, hi, nums);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(0, nums.size()-1, nums);
    }
};
