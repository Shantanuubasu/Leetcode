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

    int solve(TreeNode* root, int &moves){
        if(!root){
            return 0;
        }

        int l=solve(root->left,moves);
        int r=solve(root->right,moves);

        moves+=abs(l)+abs(r);

        return (l+r+ root->val)-1;
    }

    int distributeCoins(TreeNode* root) {
        int moves=0;

        solve(root,moves);

        return moves;
    }
};

//----------------------------------------------------------------
/* 1. We will use DFS, we will move to the left subtree and check if the nodes have any extra coins to send it to its parents.
2. For every function call, we will return the total coins a node receives from left and right child and its own coins minus 1 because it has to retain one coin.
3. We then add the abs value of left and right to the moves. */
