class Solution {
public:
    void paths(int start, vector<int>& dist , vector<vector<int>>& adj){
        int n = dist.size();
        vector<bool> vis (n,false);
        // priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        queue<pair<int,int>> pq;
        pq.push({0,start});
        dist[start] = 0;
        vis[start] = true ;
        while (!pq.empty()){
            auto [d, node] = pq.front();
            pq.pop();
            for (int neighbour:adj[node]){
                if (vis[neighbour])continue;
                vis[neighbour]=true ;
                dist[neighbour] = min(d+1, dist[neighbour]);
                pq.push({dist[neighbour],neighbour});
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dx(n,INT_MAX), dy(n,INT_MAX),dz(n,INT_MAX);
        paths(x,dx,adj);
        paths(y,dy,adj);
        paths(z,dz,adj);
        int ans = 0;
        for (int i=0;i<n;i++){
            int a = max({dx[i], dy[i], dz[i]});
            int c = min({dx[i], dy[i], dz[i]});
            int b = dx[i]+dy[i]+dz[i]-a-c;
            if (1LL*a*a == 1LL*b*b + 1LL*c*c)ans++;
        }
        return ans ;
    }
};