class SnapshotArray {
private:
    vector<vector<pair<int,int>>> arr;
    int s;
public:
    SnapshotArray(int length) {
        s = -1;
        arr.resize(length);
        for (int i=0;i<length;i++)arr[i].push_back({-1,0});
    }
    
    void set(int index, int val) {
        arr[index].push_back({s,val});
    }
    
    int snap() {
        return ++s;
    }
    
    int get(int index, int snap_id) {
        int left = 0, right = arr[index].size()-1, ans = -1;
        while (left <=right){
            int mid = left + (right-left)/2;
            int curr_snap = arr[index][mid].first, curr_val = arr[index][mid].second;
            if (curr_snap >= snap_id)right = mid-1;
            else {
                ans = curr_val;
                left = mid+1;
            }
        }
        return ans ;
    }
};