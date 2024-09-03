/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        if(root==NULL){
            return str;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();

            if(n==nullptr){
                str.append("#,");
            }
            else{
                str.append(to_string(n->val)).append(",");
                q.push(n->left);
                q.push(n->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root=new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();

            getline(s, str, ',');
            if(str=="#"){
                n->left=NULL;
            }
            else{
                n->left=new TreeNode(stoi(str));
                q.push(n->left);
            }

            getline(s, str, ',');
            if(str=="#"){
                n->right=NULL;
            }
            else{
                n->right=new TreeNode(stoi(str));
                q.push(n->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

//---------------------------------------------------------------------------------------
/* 1. In serialize(), if the root is NULL return empty string.
2. Take a queue and push root into it.
3. Now pop from q and check if it is NULL then for that append "#," to str.
4. Else, append the node's val with "," and push the left and right nodes to q.
5. Finally, return str.
6. In deserialize(), if the size of string data is 0 then return NULL.
7. Use stringstream to read each character as a stream in str and use getline to skip ',' as a delimiter.
8. Create the root node from the first value in the string.
9. Now take a queue and push root to the queue.
10. Pop from the queue and and get the next value in the string, if the value is "#" then n's left will be NULL.
11. Else, make a node for n's left and push it to q.
12. Read the next character, if that character is "#" then n's right will be NULL.
13. Else, make a node for n's right and push it to q.
14. Finally, return root. */
