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
    bool solve(TreeNode* root, long long mini, long long maxi){
        if(!root){
            return true;
        }

        if((root->val<=mini) || (root->val>=maxi)){
            return false;
        }

        bool r=solve(root->right, root->val, maxi);
        bool l=solve(root->left, mini, root->val);
        
        return r&l;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root->left, LLONG_MIN, root->val) & solve(root->right, root->val, LLONG_MAX);
    }
};

//-------------------------------------------------------------------------------------------------------------------
/* 1. We will maintain a range of accepted value in which the current root's val should lie.
2. If the root is NULL return true.
3. If the root's val goes beyond the range from mini to maxi then return false.
4. Then we recursively call the solve function for right and left child.
5. Finally, return the AND of r and l. */
