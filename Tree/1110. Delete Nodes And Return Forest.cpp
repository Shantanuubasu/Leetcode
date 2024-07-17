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
    TreeNode* deleteNode(TreeNode* root, unordered_set<int> &st, vector<TreeNode*> &res){
        if(root==NULL){
            return NULL;
        }

        root->left=deleteNode(root->left, st, res);
        root->right=deleteNode(root->right, st, res);

        if(st.find(root->val)!=st.end()){
            if(root->left!=NULL){
                res.push_back(root->left);
            }
            if(root->right!=NULL){
                res.push_back(root->right);
            }

            return NULL;
        }
        else{
            return root;
        }

        // return NULL;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ios_base::sync_with_stdio(false);

        vector<TreeNode*> res;

        unordered_set<int> st;
        for(int &i: to_delete){
            st.insert(i);
        }

        deleteNode(root, st, res);

        if(st.find(root->val)==st.end()){
            res.push_back(root);
        }

        return res;
    }
};

//---------------------------------------------------------------------------------------
/* 1. We will store all the values we need to delete in a set.
2. In deleteNode(), If root is NULL then we return NULL.
3. We go to the leaf nodes and get left and right child of root.
4. If we find the value of root in the set then we push the left and right child of it in the res and return NULL.
5. Else, we return root.
6. Then we check if root needs to be deleted, if it is not present in set then add to res.
7. Finally, return res. */
