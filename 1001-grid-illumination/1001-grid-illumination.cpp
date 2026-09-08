#define vi vector<int> 
#define vvi vector<vi>
class Solution {
public:
    vi gridIllumination(int n, vvi& lamps, vvi& queries) {
        unordered_map<int,int> row,col,d1,d2;
        map<pair<int,int>,int> mp;
        vi ans ;
        int dx[3] = {-1,0,1}, dy[3] = {-1,0,1};
        for (auto i:lamps){
            int x = i[0], y = i[1];
            mp[{x,y}]++;
            row[x]++;
            col[y]++;
            d1[y-x]++;
            d2[x+y]++;
        }
        for (auto q:queries){
            int x = q[0], y=q[1], temp = 0;
            if (row.find(x) != row.end() and row[x] > 0)temp = 1;
            if (col.find(y) != col.end() and col[y] > 0)temp = 1;
            if (d1.find(y-x) != d1.end() and d1[y-x] > 0)temp = 1;
            if (d2.find(x+y) != d2.end() and d2[y+x] > 0)temp = 1;
            ans.push_back(temp);
            for (int i=0;i<=2;i++){
                for (int j=0;j<=2;j++){
                    int nx = dx[i]+x, ny = y+dy[j];
                    if (nx<0 or nx>=n or ny<0 or ny>=n)continue;
                    if (mp.find({nx,ny}) != mp.end() and mp[{nx,ny}]){
                        int t = mp[{nx,ny}];
                        mp[{nx,ny}]=0;
                        row[nx]-=t;
                        col[ny]-=t;
                        d1[ny-nx]-=t;
                        d2[ny+nx]-=t;
                    }
                }
            }
        }
        return ans ;
    }
};