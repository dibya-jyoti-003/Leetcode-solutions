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
    int total_nodes = 0;
    pair<TreeNode*,bool> buildTree(int val, int low, int high,unordered_map<int,TreeNode*>& mp){
        if (val < low or val > high)return {nullptr,false};
        TreeNode* root = mp[val];
        TreeNode *ln = nullptr, *rn = nullptr;
        bool lb = true, rb = true;
        if (root->left){
            auto left = buildTree(root->left->val, low,val-1,mp);
            ln = left.first;
            lb = left.second;
        }
        if (root->right){
            auto right = buildTree(root->right->val, val+1,high,mp);
            rn = right.first;
            rb = right.second;
        }
        if (!lb or !rb)return {nullptr,false};
        root->left = ln;
        root->right = rn;
        total_nodes++;
        return {root,true};
    }
    
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*> mp;
        int len = trees.size();
        int arr[50001]={0};
        for (auto i:trees){
            mp[i->val]=i;
            arr[i->val]++;
            if (i->left){
                int left = i->left->val;
                arr[left]--;
                if (mp.find(left) == mp.end())mp[left] = i->left;
            }
            if (i->right){
                int right = i->right->val;
                arr[right]--;
                if (mp.find(right) == mp.end())mp[right]=i->right;
            }
        }
        int val=0, cnt=0 ;
        for (int i=0;i<=50000;i++){
            if (arr[i] == 1){
                val = i;
                cnt++;
                if (cnt > 1)return nullptr;
            }
        }
        if (cnt == 0)return nullptr;
        auto [root,flag] = buildTree(val,1,5e4,mp);
        if (!flag or mp.size() != total_nodes)return nullptr;
        return root;
    }
};