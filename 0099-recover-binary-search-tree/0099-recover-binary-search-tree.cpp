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
private:
    TreeNode *prev,*first,*second;
    void solve(TreeNode* curr){
        if (!curr)return ;
        solve(curr->left);
        if (prev and prev->val > curr->val ){
            if (!first)first = prev;
            second = curr;
        }
        prev = curr;
        solve(curr->right);
    }
public:
    Solution(){
        prev = first = second = nullptr;
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        swap(first->val, second->val);
    }
};