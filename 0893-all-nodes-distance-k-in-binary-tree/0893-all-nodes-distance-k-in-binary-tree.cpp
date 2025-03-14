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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        unordered_map<int,TreeNode*> parent;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto top=q.front();
                q.pop();
                if(top->left){
                    parent[top->left->val]=top;
                    q.push(top->left);
                }
                if(top->right){
                    parent[top->right->val]=top;
                    q.push(top->right);
                }
            }
        }
    
        unordered_map<int,int> went;
        q.push(target);
        while(k-- && !q.empty()){
            int length=q.size();
            for(int i=0;i<length;i++){
                auto top=q.front();
                q.pop();
                went[top->val]=1;
                if(top->left && !went[top->left->val]) q.push(top->left);
                if(top->right && !went[top->right->val]) q.push(top->right);
                if(parent[top->val] && !went[parent[top->val]->val]) q.push(parent[top->val]);
            }
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};