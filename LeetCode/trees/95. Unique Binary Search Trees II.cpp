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
    vector<TreeNode *> generateTrees(int low, int high) {
        if(low > high) return {nullptr};

        vector<TreeNode *> nodes;
        for(int val=low; val<=high; ++val) {
            vector<TreeNode *> leftChildren = generateTrees(low, val-1);
            vector<TreeNode *> rightChildren = generateTrees(val+1, high);

            for(auto left: leftChildren) {
                for(auto right: rightChildren) {
                    TreeNode *node = new TreeNode(val, left, right);
                    nodes.push_back(node);
                }
            }
        }

        return nodes;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};
