class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n=grid[0].size();
        if (grid[0][0] == ')' or grid[m-1][n-1] == '(' or (m+n-1)%2) return false;
        unordered_set<int> arr[101][101];
        arr[0][0].insert(1);
        int sign = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (!i and !j)continue;
                char ch = grid[i][j];
                if (ch == ')')sign=-1;
                else sign = 1;
                if (j>0){
                    for (int p:arr[i][j-1]){
                        if (p+sign >= 0)arr[i][j].insert(p+sign);
                    }
                }
                if (i>0){
                    for (int p:arr[i-1][j]){
                        if (p+sign >= 0)arr[i][j].insert(p+sign);
                    }
                }
            }
        }
        return arr[m-1][n-1].find(0) != arr[m-1][n-1].end();
    }
};
