#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
class Solution {
private:
    int n,curPos;
    vvi adj;
    vi parent, depth, heavy, head, pos, val;

    struct SegmentTree{
        int size;
        vi tree;
        SegmentTree(int n){
            size = n;
            tree.assign(4 * n, 0);
        }
        void update(int node, int start, int end, int idx, int val){
            if(start == end){
                tree[node] = val;
                return;
            }
            int mid = start + (end - start) / 2;
            if(idx <= mid) update(2 * node, start, mid, idx, val);
            else update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }

        int query(int node, int start, int end, int l, int r){
            if(r < start || end < l)return 0;
            if(l <= start && end <= r)return tree[node];
            int mid = start + (end - start) / 2;
            return query(2 * node, start, mid, l, r) ^ query(2 * node + 1, mid + 1, end, l, r);
        }
    };

    int dfs(int u, int p, int d){
        depth[u] = d;
        parent[u] = p;
        int size = 1, maxChildSize = 0;
        for(int v : adj[u]){
            if(v != p){
                int childSize = dfs(v, u, d + 1);
                size += childSize;
                if(childSize > maxChildSize){
                    maxChildSize = childSize;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    void decompose(int u, int h){
        head[u] = h;
        pos[u] = curPos++;
        if(heavy[u] != -1)decompose(heavy[u], h);
        for(int v : adj[u]){
            if(v != parent[u] && v != heavy[u])decompose(v, v);
        }
    }

    int queryPath(int u, int v, SegmentTree& segTree){
        int res = 0;
        while(head[u] != head[v]){
            if(depth[head[u]] > depth[head[v]])swap(u, v);
            res ^= segTree.query(1, 0, n - 1, pos[head[v]], pos[v]);
            v = parent[head[v]];
        }
        if(depth[u] > depth[v])swap(u, v);
        res ^= segTree.query(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }

public:
    vb palindromePath(int n, vvi& edges, string s, vector<string>& queries){
        this->n = n;
        adj.assign(n, vi());

        for(const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        dfs(0, -1, 0);
        curPos = 0;
        decompose(0, 0);
        SegmentTree segTree(n);
        val.resize(n);
        for(int i = 0; i < n; i++){
            val[i] = 1 << (s[i] - 'a');
            segTree.update(1, 0, n - 1, pos[i], val[i]);
        }
        vb ans;
        for(const string& q : queries){
            stringstream ss(q);
            string type;
            ss >> type;
            if(type == "update"){
                int u;
                char c;
                ss >> u >> c;
                val[u] = 1 << (c - 'a');
                segTree.update(1, 0, n - 1, pos[u], val[u]);
            }
            else {
                int u, v;
                ss >> u >> v;
                int mask = queryPath(u, v, segTree);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};