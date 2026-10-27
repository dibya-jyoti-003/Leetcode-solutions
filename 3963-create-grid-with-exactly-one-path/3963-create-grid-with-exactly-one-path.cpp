class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m);
        for (int i=0;i<m;i++){
            string temp="";
            for (int j=0;j<n;j++)temp = (i==0 or j==n-1)?temp+'.':temp+'#';
            ans[i]=temp;
        }
        return ans ;
    }
};