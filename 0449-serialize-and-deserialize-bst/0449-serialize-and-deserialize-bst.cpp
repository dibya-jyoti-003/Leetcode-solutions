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
    int i= 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)return "";
        return ""+to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nodes ;
        for (int i=0;i<data.size();i++){
            int value = 0;
            while (data[i] != ','){
                value = value * 10 + (data[i]-'0');
                i++;
            }
            nodes.push_back(value);
        }
        return solve(nodes,0,nodes.size()-1);
    }

    TreeNode* solve(vector<int>& nodes, int start, int end){
        if (start > end)return nullptr;
        TreeNode* temp = new TreeNode(nodes[start]);
        if (start == end)return temp;
        int left = start+1, right = end ,pos ;
        while (left <= right){
            int mid = left + (right-left)/2;
            if (nodes[mid] < nodes[start]){
                pos = mid;
                left =  mid+1;
            }
            else right = mid-1;
        }
        temp->left = solve(nodes,start+1,pos);
        temp->right = solve(nodes,pos+1,end);
        return temp;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;