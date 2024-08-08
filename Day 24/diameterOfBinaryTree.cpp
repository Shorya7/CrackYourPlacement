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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        maxi(root,diameter);
        return diameter;
    }
    int maxi(TreeNode* root,int& m){
        if (root==NULL) return 0;
        int l=maxi(root->left, m);
        int r=maxi(root->right,m);

        m=max(l+r,m);

        return 1+max(l,r);
    }
};