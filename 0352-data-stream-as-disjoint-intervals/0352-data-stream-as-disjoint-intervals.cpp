#define vvi vector<vector<int>>
class SummaryRanges {
private:
    set<int> nums;
public:
    SummaryRanges(){}
    void addNum(int value) {
        nums.insert(value);
    }
    vvi getIntervals() {
        vvi result;
        for(int num:nums){
            if( !result.empty() and result.back()[1]+1==num)result.back()[1]=num;
            else result.push_back({num,num});
        }
        return result;
    }
};
