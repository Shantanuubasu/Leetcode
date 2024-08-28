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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        if(root){
            q1.push(root);
        }
        while(!q1.empty()){

            int k=q1.size();
            cout<<k<<endl;
            while(k--){
                TreeNode* n=q1.front();
                q1.pop();

                if(k==0){
                    ans.push_back(n->val);
                }

                if(n->left){
                    q2.push(n->left);
                }

                if(n->right){
                    q2.push(n->right);
                }

                while(!q2.empty()){
                    TreeNode* node=q2.front();
                    q2.pop();
                    q1.push(node);
                }
            }
        }

        return ans;
    }
};

//-------------------------------------------------------------------------
/* 1. Take an ans array to store the answers, two queues to use in level order traversal.
2. If root is not null then push it into q1.
3. Now while q1 is not empty we will find the last element in each level of tree and add it to ans.
4. We pop from q1 and if k is equal to 9 then it means it is the last element in the level, so we push it to ans.
5. Now we will add the left and right child of n to q2. This q2 will act as a waiting queue which will store the elements in the next level.
6. So now after the ending each level we will move contents of q2 to q1.
7. Finally, return ans. */
