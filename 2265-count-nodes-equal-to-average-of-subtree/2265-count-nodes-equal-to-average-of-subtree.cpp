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
    int cnt = 0;
    pair<int,int> solve(TreeNode* curr){
        if (!curr)return {0,0};
        auto [l_total,l_num] = solve(curr->left);
        auto [r_total,r_num] = solve(curr->right);
        int total = l_total + r_total + curr->val;
        int num = 1+l_num+r_num;
        if (total/num == curr->val)cnt++;
        return {total,num};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        auto [a,b] = solve(root);
        return cnt;
    }
};