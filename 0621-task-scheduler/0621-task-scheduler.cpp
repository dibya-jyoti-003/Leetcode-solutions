class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26]={0};
        for (char ch :tasks)cnt[ch-'A']++;
        priority_queue<int> pq;
        for (int i=0;i<26;i++){
            if (cnt[i]>0)pq.push(cnt[i]);
        }
        int ans = 0;
        while (!pq.empty()){
            int cycle = n+1, temp_cnt=0;
            vector<int> temp;
            while (cycle-- > 0 and !pq.empty()){
                int top = pq.top();
                pq.pop();
                if (--top)temp.push_back(top);
                temp_cnt++;
            }
            if (temp.size() > 0)ans += n+1;
            else ans += temp_cnt;
            for (auto i:temp)pq.push(i);
        }
        return ans ;
    }
};

