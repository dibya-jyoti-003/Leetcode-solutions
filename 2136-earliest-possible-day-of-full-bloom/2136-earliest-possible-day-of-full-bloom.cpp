#define f first
#define s second
#define pii pair<int,int>
class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n = p.size();
        vector<pii> arr(n);
        for (int i=0;i<n;i++)arr[i] = {p[i],g[i]};
        sort (arr.begin(), arr.end(), [&](const pii& a, const pii& b){
            return a.s > b.s;
        });
        for (auto [a,b]:arr)cout <<a<<" "<<b<<endl;
        int ans = 0, curr =0 ;
        for (int i=0;i<n;i++){
            ans = max(ans , curr + arr[i].f+arr[i].s);
            curr += arr[i].f;
        }
        return ans ;
    }
};