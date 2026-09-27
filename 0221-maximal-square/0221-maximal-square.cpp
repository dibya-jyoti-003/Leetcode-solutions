class Solution {
private:
    int root (int x){
        int i=0;
        for (;i*i<=x;i++);
        return i-1;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        tuple<int,int,int> arr1[300], arr2[300], zero = {0,0,0};
        int ans = 0, m = matrix.size(), n=matrix[0].size();
        for (int j=0;j<n;j++){
            if (matrix[0][j] == '0'){
                arr1[j] = zero;
                continue;
            }
            auto [_,h,_] = (j>0)? arr1[j-1] :zero;
            arr1[j] = {1,h+1,1};
            ans = 1;
        }
        for (int i=1;i<m;i++){
            for (int j=0;j<n;j++){
                if (matrix[i][j] == '0'){
                    arr2[j] = zero;
                    continue;
                }
                auto [d,_,_] = (j>0)? arr1[j-1]:zero;
                auto [_,h,_] = (j>0)? arr2[j-1] :zero;
                auto [_,_,v] = arr1[j];  
                arr2[j] = {min({d,h,v})+1,h+1,v+1};
                ans = max(ans,min({d,h,v}) +1);          
            }
            for (int j=0;j<n;j++)arr1[j] =  arr2[j];
        }
        return ans*ans;
    }
};