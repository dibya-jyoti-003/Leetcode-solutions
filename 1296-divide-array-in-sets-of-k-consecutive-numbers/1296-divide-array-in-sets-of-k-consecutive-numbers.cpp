class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<int,vector<int>,greater<>> pq;
        for (int a : nums){
            if (mp.find(a) == mp.end()){
                mp[a]=1;
                pq.push(a);
            }
            else mp[a]++;
        }
        while (true){
            while (!pq.empty() and mp[pq.top()]==0)pq.pop();
            if (pq.empty())break;
            int mini = pq.top();
            mp[mini]--;
            if (mp[mini] == 0)pq.pop();
            for (int i=1;i<k;i++){
                if (mp[mini+i]==0)return false;
                else mp[mini+i]--;
            }
        }
        return true ;
    }
};