class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        int diff = 1, len = rest.size();
        sort(rest.begin(), rest.end());
        if (len==0 or rest[len-1][0] != n){
            rest.push_back({n,n-1});
            len++;
        }
        for (int i=0;i<len;i++){
            rest[i][1] = min(rest[i][1], rest[i][0]-diff);
            diff = rest[i][0] - rest[i][1];
        }
        for (int i=len-2;i>=0;i--){
            rest[i][1] = min(rest[i][1],rest[i+1][1]+rest[i+1][0]-rest[i][0]);
        }
        int peak = 0;
        int x1=1, y1=0;
        for (int i=0;i<len;i++){
            int x2=rest[i][0], y2=rest[i][1];
            int ypeak = (x2-x1+y2+y1)/2;
            peak = max(peak,ypeak);
            x1 = x2;
            y1 = y2;
        }
        return peak;
    }
};