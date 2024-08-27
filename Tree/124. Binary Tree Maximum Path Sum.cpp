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
    int solve(TreeNode* root, int &maxi){
        if(root==NULL){
            return 0;
        }

        int l=solve(root->left, maxi);
        int r=solve(root->right, maxi);
    
        if(l<0){
            l=0;
        }
        if(r<0){
            r=0;
        }

        maxi=max(maxi, l+r+root->val);

        return max(l,r)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi=root->val;
        solve(root ,maxi);
        return maxi;
    }
};

//-------------------------------------------------
/* 1. In solve(), we first check if root is NULL, if yes then we return 0.
2. Now we call solve() for both l which will calculate the path sum for left node and r which will calculate the path sum for right node.
3. Now we don't want negative numbers to be included in our sum, so we will make l or r as 0 if they are less than 0.
4. Now update the maxi as maximum of maxi or sum of l,r and root's value.
5. Return maximum of l or r sum plus root's val. */
