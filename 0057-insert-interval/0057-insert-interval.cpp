#define vi vector<int>
#define vvi vector<vi>
class Solution {
public:
    vvi insert(vector<vector<int>>& intervals, vi& newInterval) {
        int len = intervals.size() ;
        vvi ans , temp;
        for (int i=0;i<len;i++){
            temp.push_back({intervals[i][0], -1});
            temp.push_back({intervals[i][1], 1});
        }
        temp.push_back({newInterval[0], -1});
        temp.push_back({newInterval[1], 1});
        sort(temp.begin(), temp.end());
        int left, t1 = 0, t2 = 0 ;
        for (int i=0;i<2*(len+1);i++){
            t2 += temp[i][1];
            if (t2<0 and !t1)left = temp[i][0];
            else if (!t2 and t1<0)ans.push_back({left,temp[i][0]});
            t1 = t2;
        }
        return ans ;
    }
};