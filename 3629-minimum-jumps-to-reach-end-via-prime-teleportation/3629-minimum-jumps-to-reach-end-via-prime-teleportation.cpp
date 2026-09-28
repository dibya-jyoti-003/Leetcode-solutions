class Solution {
public:
    int minJumps(vector<int>& nums) {
        int len = nums.size(), maxi = INT_MIN, dist = 0;
        queue<int> q;
        q.push(0);
        vector<bool> vis(len, false);
        vis[0] = true ;
        unordered_map<int,vector<int>> mp;
        for (int i=0;i<len;i++){
            maxi = max(maxi, nums[i]);
            mp[nums[i]].push_back(i);
        }
        vector<bool> is_prime(maxi+1,true);
        is_prime[0] = is_prime[1] = false;
        for (int i=2;i<=maxi;i++){
            if (!is_prime[i])continue;
            for (int val = i*2;val<=maxi;val += i)is_prime[val] = false;
        }
        vector<bool> seen(maxi+1,false);
        while (!q.empty()){
            int size = q.size();
            while (size--){
                int curr = q.front();
                if (curr == len -1)return dist;
                q.pop();
                if (curr > 0 and !vis[curr-1]){
                    q.push(curr-1);
                    vis[curr-1]=true ;
                }
                if (curr < len-1 and !vis[curr+1]){
                    q.push(curr+1);
                    vis[curr+1]=true ;
                }
                if (is_prime[nums[curr]] and !seen[nums[curr]]){
                    for (int mult = nums[curr];mult<=maxi;mult += nums[curr]){
                        if (mp.find(mult) != mp.end()){
                            for (int p:mp[mult]){
                                if (!vis[p]){
                                    q.push(p);
                                    vis[p] = true ;
                                }
                            }
                        }
                    }
                    seen[nums[curr]] = true ;
                }
            }
            dist++;
        }
        return 0;
    }
};