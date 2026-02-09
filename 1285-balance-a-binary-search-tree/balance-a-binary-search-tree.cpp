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
    void inorder(vector<int> &inord, TreeNode* root){
        if(root==NULL) return;

        inorder(inord,root->left);
        inord.push_back(root->val);
        inorder(inord,root->right);
    }
    TreeNode* build(vector<int> &arr,int leftInd, int rightInd){

        if(leftInd>rightInd) return NULL;

        // mid is going to be root at a particular level
        int mid = leftInd + (rightInd-leftInd)/2;

        TreeNode* root = new TreeNode(arr[mid]);

        // we will fill the tree recursively , by considering left subarray and then right subarray
        root->left = build(arr,leftInd,mid-1);
        root->right = build(arr,mid+1,rightInd);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // finding the inorder traversal of the giver tree 
        // sorted milega
        vector<int> inord;
        inorder(inord,root);

        return build(inord,0,inord.size()-1);
    }
};