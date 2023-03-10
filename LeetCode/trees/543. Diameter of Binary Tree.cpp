/*
SAME CONCEPT AS PROBLEM: 124. Binary Tree Maximum Path Sum
    - Problem Statement: https://leetcode.com/problems/binary-tree-maximum-path-sum/
    - My Solution: https://github.com/sahsan73/problems-solutions/blob/main/LeetCode/trees/124.%20Binary%20Tree%20Maximum%20Path%20Sum.cpp

COMPLEXITY:
    - TC = O(n)
    - SC = O(1)
*/

class Solution {
private:
    int answer;

    int dfs(TreeNode *root) {
        if(root == nullptr) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        answer = max(answer, l+r);
        return 1+max(l, r);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        answer = INT_MIN;
        dfs(root);
        return answer;
    }
};
