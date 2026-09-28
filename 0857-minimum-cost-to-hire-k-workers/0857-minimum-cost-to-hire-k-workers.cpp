class Solution {
private:
    double min(double a , double b){
        if (a<b)return a ;
        return b ;
    }
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        priority_queue<int> pq;
        int len = wage.size();
        vector<pair<double,int>> ratio ;
        for (int i=0;i<len;i++)ratio.push_back({(wage[i]*1.0)/(quality[i]*1.0),quality[i]});
        sort(ratio.begin(), ratio.end());
        long long res = 0;
        for (int i=0;i<=k-1;i++){
            pq.push(ratio[i].second);
            res += ratio[i].second;
        }
        double ans = (res + 0.0) * ratio[k-1].first;
        for (int i=k;i<len;i++){
            int curr = ratio[i].second;
            pq.push(curr);
            int prev = pq.top();
            pq.pop();
            res += curr-prev;
            ans = min(ans , ratio[i].first * (res + 0.0));
        }
        return ans ;
    }
};