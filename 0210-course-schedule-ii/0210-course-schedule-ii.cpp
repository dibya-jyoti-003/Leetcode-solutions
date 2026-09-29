class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans, indegree(numCourses,0) ;
        unordered_set<int> myset;
        vector<vector<int>> adj(numCourses);
        for (auto sub:prerequisites){
            adj[sub[1]].push_back(sub[0]);
            indegree[sub[0]]++;
        }
        for (int i=0;i<numCourses;i++){
            if (indegree[i] == 0)myset.insert(i);
        }
        while (!myset.empty()){
            int size = myset.size();
            while (size--){
                int node = *myset.begin();
                myset.erase(node);
                ans.push_back(node);
                for (auto j:adj[node]){
                    indegree[j]--;
                    if (indegree[j] == 0)myset.insert(j);
                }
            }
        }
        vector<int> empty;
        return (ans.size()!=numCourses)?empty:ans ;
    }
};
