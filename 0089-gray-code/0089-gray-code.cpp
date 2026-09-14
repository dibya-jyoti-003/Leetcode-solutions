#define vi vector<int>
class Solution {
public:
    vi grayCode(int n) {
        vi gray ;
        gray.push_back(0);
        gray.push_back(1);
        for (int i=2;i<=n;i++){
            int len = gray.size();
            for (int j=len-1;j>=0;j--)gray.push_back(gray[j] | (1<<(i-1)));
        }
        return gray;
    }
};