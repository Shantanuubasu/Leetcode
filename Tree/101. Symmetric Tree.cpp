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
    bool solve(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }

        if(root1==NULL || root2==NULL){
            return false;
        }

        return ((root1->val == root2->val) && solve(root1->left, root2->right) && solve(root1->right, root2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return solve(root->left, root->right);
    }
};

//--------------------------------------------------------------------------------------------------------------------------------------
/* 1. Consider two subtrees one to the left of root and one to the right.
2. root1 will traverse in left subtree and root2 will traverse in right subtree.
3. Now Check if both root1 and root2 are NULL then return true.
4. If either one of them is NULL then return false.
5. If both have same node's val and call solve again with moving root1 to left and root2 to right as it is a mirror image.
6. Also call the solve function when root1 goes right and root2 goes left. */
