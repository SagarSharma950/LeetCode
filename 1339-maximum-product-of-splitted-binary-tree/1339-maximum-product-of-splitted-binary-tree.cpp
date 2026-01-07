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
    int mod=1e9+7;
    long total=0;
    long maxpro=0;
    int sum(TreeNode* root){
        if(root==NULL) return 0;
        int leftsum=sum(root->left);
        int rightsum=sum(root->right);
        long tsum=root->val+leftsum+rightsum;
        long remainingsum=total-tsum;
        maxpro=max(maxpro, tsum*remainingsum);
        return tsum;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL) return 0;
        maxpro=0;
        total=sum(root);
        sum(root);
        return maxpro%mod;
    }
};