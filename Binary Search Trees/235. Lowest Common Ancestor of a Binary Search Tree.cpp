/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } 
        else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};

//--------------------------------------------------------------------------------------------------
/* 1. If the value of current root is greater than that of p and q then there is no point in searching in right subtree. So, we search in the left subtree.
2. Similarly, if the value of current root is lesser than that of p and q then we will search in the right subtree.
3. If the above two conditions don't satisfy then we have found the answer. So, we return root. */
