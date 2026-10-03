#define vvi vector<vector<int>>
class SummaryRanges {
private:
    set<int> start, end ;
    unordered_map<int,int> mp, vis;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(vis.find(value) != vis.end())return ;
        vis[value] = 1;
        int left, right;
        bool r_interval = start.find(value+1) != start.end(), l_interval = end.find(value-1) != end.end(); 
        if (!r_interval and !l_interval ){
            start.insert(value);
            end.insert(value);
            mp[value] = value;
        }
        else if (r_interval and !l_interval){
            left = value+1;
            right = mp[left];
            mp.erase(left);
            start.erase(left);
            start.insert(value);
            mp[right] = value;
            mp[value] = right; 
        }
        else if (!r_interval and l_interval){
            right = value-1;
            left = mp[right];
            mp.erase(right);
            end.erase(right);
            end.insert(value);
            mp[left] = value;
            mp[value] = left; 
        }
        else {
            left = mp[value-1];
            right = mp[value+1];
            start.erase(value+1);
            end.erase(value-1);
            mp[right] = left;
            mp[left] = right;
        }
    }
    
    vvi getIntervals() {
        vvi ans ;
        for (int i:start)ans.push_back({i,mp[i]});
        return ans ;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */