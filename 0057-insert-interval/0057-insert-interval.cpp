#define vi vector<int>
#define vvi vector<vi>
class Solution {
public:
    vvi insert(vvi& range, vi& n_range) {
        vvi ans;
        int pos = 0, len = range.size();
        while(pos<len and range[pos][1] < n_range[0]) ans.push_back(range[pos++]);
        while(pos<len and range[pos][0] <= n_range[1])n_range = {min(n_range[0], range[pos][0]),max(n_range[1], range[pos++][1])};
        ans.push_back(n_range);
        while(pos<len)ans.push_back(range[pos++]);
        return ans;
    }
};