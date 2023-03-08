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

/*
For subarrays, pre[a...b] and post[c...d], we know that pre[a]==post[d]
    - [root][.....left.....][...right...]   <=== preorder traversal
    - [.....left.....][...right...][root]   <=== postorder traversal
    
If the current node is pre[a]
    - find the index of pre[a+1] in post[c...d] say (idx), we know that left subtree should
      be constructed from pre[a+1...a+(idx-c+1)] and post[c...idx], note (idx-c+1) is the length of the subarray(post).
    - Similary, the right subtree should be constructed from pre[a+(idx-c+1)+1...b] and post[idx+1...d-1]
    
    - If idx==d-1, there's NO right child
*/

class Solution {
private:
    unordered_map<int, int> postIdx;
    vector<int> pre;

    // pre[a....b], post[c....d]
    TreeNode *constructFromPrePost(int a, int b, int c, int d) {
        if(a == b) return (new TreeNode(pre[a])); // Important

        TreeNode *node = new TreeNode(pre[a]);
        int idx = postIdx[pre[a+1]];
        int len = idx - c + 1;
        
        node->left = constructFromPrePost(a+1, a+len, c, idx);
        if(idx == d-1) return node; // there's no right child
        node->right = constructFromPrePost(a+len+1, b, idx+1, d-1);
        return node;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = (int)preorder.size();
        this->pre = preorder;
        
        postIdx.clear();
        for(int i=0; i<n; ++i) postIdx[postorder[i]] = i;

        return constructFromPrePost(0, n-1, 0, n-1);
    }
};
