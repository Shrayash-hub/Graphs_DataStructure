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
    bool isBalanced(TreeNode* root) {
        // balanced height of a subtree means that |height of left subtree - height of right subtree| <= 1
        return height(root)!=-1;
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int LF = height(root->left);
        if(LF==-1) return -1;
        int RF = height(root->right);
        if(RF==-1) return -1;
        if(abs(LF-RF)>1) return -1;
        return 1+max(LF,RF);
    }
};