class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        for (int i=1-n;i<n;i++){
            for (int j=1-n;j<n;j++){
                int temp = 0;
                for (int p=0;p<n;p++){
                    for (int q=0;q<n;q++){
                        int img1_num = (p+i >= 0 and p+i<n and q+j>=0 and q+j<n)?img1[p+i][q+j]:0;
                        temp += (img1_num and img1_num == img2[p][q]);
                    }
                }
                ans = max(ans,temp);
            }
        }
        return ans ;
    }
};