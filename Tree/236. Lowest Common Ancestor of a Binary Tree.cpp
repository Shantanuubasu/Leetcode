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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }

        TreeNode* l=solve(root->left, p ,q);
        TreeNode* r=solve(root->right, p ,q);

        if(l!=NULL && r!=NULL){
            return root;
        }
        else if(l==NULL){
            return r;
        }
        
        return l;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p , q);
    }
};

//-------------------------------------------------------------------------------------------
/* 1. In solve(), we first check root is null or root is p or root is q if any of this condition satisfies then return root as it will be the lowest common ancestor.
2. Now we will apply dfs in left subtree and right subtree and store the result in l and r.
3. If both l and r are not null that means we have found p and q in left and right subtree. So, return root.
4. If l is null that means both nodes are found in right subtree so return r.
5. else both nodes are found in left subtree so return l. */
