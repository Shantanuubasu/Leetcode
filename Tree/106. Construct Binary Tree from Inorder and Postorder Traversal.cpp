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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int postst, int postend, int inst, int inend, unordered_map<int, int>& mp){
        if(postst>postend || inst>inend){
            return NULL;
        }

        TreeNode* root=new TreeNode(postorder[postend]);
        int inroot=mp[postorder[postend]];
        int leftnodes=inroot-inst;
        int rightnodes=inend-inroot;
        

        root->left=solve(inorder, postorder, postst, postst+leftnodes-1, inst, inroot-1, mp);
        root->right=solve(inorder, postorder, postend-rightnodes, postend-1, inroot+1, inend, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;


        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }

        return solve(inorder, postorder, 0, postorder.size()-1, 0, inorder.size()-1, mp);
    }
};

//--------------------------------------------------------------------------------------------------------------------
/* 1. First we map all the elements of inorder to its index.
2. Now in solve function, we first check if starting index of postorder is greater than ending index or starting index of inorder is greater than ending then return NULL.
3. Make the root of the tree which will be the last element in postorder.
4. Find the index of root in inorder as inroot.
5. Now find the number of nodes in left and right subtrees as leftnodes and rightnodes.
6. Then solve for root left, now pass starting index of postorder as postst and ending as postst+leftnodes-1 to include all the nodes in left subtree.
7. Also, starting index of inorder would be inst and ending would be the index before root which is inroot-1.
8. Now solve for right, the starting index of postorder would be the nodes before the root which is postend-rightnodes and the ending would be the node before the root which is postend-1.
9. Also, in inorder the starting index would be the one after root which is inroot+1 and the ending would be inend.
10. Finally, return the root. */
