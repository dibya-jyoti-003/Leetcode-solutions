class Solution {
private:
    int root (int x){
        int i=0;
        for (;i*i<=x;i++);
        return i-1;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        tuple<int,int,int> arr[300][300] ;
        int ans = INT_MIN;
        int m = matrix.size(), n=matrix[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (matrix[i][j] == '0')arr[i][j] = {0,0,0};
                else {
                    tuple<int,int,int> one = {0,0,0};
                    auto [d,_,_] = (i>0 and j>0)? arr[i-1][j-1]:one;
                    auto [_,h,_] = (j>0)? arr[i][j-1] :one;
                    auto [_,_,v] = (i>0)? arr[i-1][j]:one;
                    int side = min({root(d),h,v});  
                    int area = (side+1)*(side+1);
                    arr[i][j] = {area,h+1,v+1};
                    ans = max(ans,area);          
                }
            }
        }
        return (ans<0)?0:ans  ;
    }
};