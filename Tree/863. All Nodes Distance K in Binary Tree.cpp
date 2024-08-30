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
    bool isvisited(TreeNode* root, vector<TreeNode*> &visited){
        for(auto i: visited){
            if(root==i){
                return true;
            }
        }

        return false;
    }

    void solve(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*> parent, vector<TreeNode*> &visited, vector<int> &ans){
        if(isvisited(root, visited)){
            return;
        }
        else{
            visited.push_back(root);
        }

        if(k==0){
            ans.push_back(root->val);
            return;
        }

        if(root->left){
            solve(root->left, k-1, parent, visited, ans);
        }
        if(root->right){
            solve(root->right, k-1, parent, visited, ans);
        }
        if(parent.find(root)!=parent.end()){
            solve(parent[root], k-1, parent, visited, ans);
        }
    }

    void bfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();

            if(n->left){
                parent[n->left]=n;
                q.push(n->left);
            }

            if(n->right){
                parent[n->right]=n;
                q.push(n->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        bfs(root, parent);
        vector<TreeNode*> visited;
        vector<int> ans;
        solve(target, k, parent, visited, ans);

        return ans;
    }
};

//-------------------------------------------------------------------------------------------
/* 1. We will first map every node to its parent for this we will use a map named parent and call bfs function to map each node to its parent.
2. Now as we have mapped the nodes to its parent we can now traverse backwards in the tree.
3. Take a visited array to keep track of visited nodes and ans to store answer values.
4. Now in solve function, We start the dfs traversal from target node.
5. First we check if the current node is visited or not, this can be checked using isvisited helper function.
6. else we add the current node to visited array.
7. Now if the value of k is 0 that means we have reached the node at distance k from target so we add the node's val to ans array and return.
8. Now do the dfs traversal from left child node, right child node and parent of the node and decrement k in every function call.
9. Finally, return ans. */
