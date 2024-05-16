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
    bool evaluateTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);

        if(!root->left &&  !root->right){
            return root->val;
        }
        bool l=evaluateTree(root->left);
        bool r=evaluateTree(root->right);

        return (root->val==3) ? l&r : l|r;
    }
};

//-------------------------------------------------------------------------
/* 1. We will use post order traversal, we will go to the left most leaf node first.
2. Then after we have evaluated that, we go to right subtree.
3. If we get to the root of the tree then we return its value.
4. We also check if root's value is 3 then we will do boolean AND, otherwise boolean OR. */
