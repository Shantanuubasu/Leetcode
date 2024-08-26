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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int k=q.size();
            vector<int> v;
            for(int i=0; i<k; i++){
                TreeNode* n=q.front();
                q.pop();
                v.push_back(n->val);
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};

//---------------------------------------------------------------
/* 1. If the root is NULL then we return empty array.
2. Take a queue and push root to it.
3. Now for each level with k nodes we pop from q and push the node's val to v.
4. Now we check if left is NULL, if not then add left node to queue.
5. Also, check if right is NULL, if not then add the right node to queue.
6. Now push the v array to ans.
7. Finally, return ans. */
