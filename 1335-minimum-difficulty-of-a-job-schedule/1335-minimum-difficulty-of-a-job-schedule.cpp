
#define vi vector<int>
class Solution {
private :
    int sgt[1200]={0};
    void buildtree(int start, int end, vi& jd, int index){
        if (start > end)return ;
        if (start == end){
            sgt[index] = jd[start];
            return ;
        }
        int mid = start+(end-start)/2;
        buildtree(start,mid,jd,index*2+1);
        buildtree(mid+1,end,jd,index*2+2);
        sgt[index] = max(sgt[index*2+1],sgt[index*2+2]);
    }
    int getmax(int start, int end,int index, int low, int high){
        if (low > end or high < start)return INT_MIN;
        if (low <= start and high >= end)return sgt[index];
        int mid = start + (end-start)/2;
        return max(getmax(start,mid,index*2+1,low,high), getmax(mid+1,end,index*2+2,low,high));
    }

public:
    int minDifficulty(vi& jd, int d) {
        int arr1[300], arr2[300], len = jd.size();
        if (d>len)return -1;
        buildtree(0,len-1,jd,0);
        arr1[0] = jd[0];arr2[0] = INT_MAX;
        //cout << arr1[0]<<" ";
        for (int i=1;i<len;i++){
            arr1[i] = max(jd[i],arr1[i-1]);
            arr2[i] = INT_MAX;
            //cout <<arr1[i]<<" ";
        }
        //cout <<endl;
        for (int n=1;n<d;n++){
            for (int pos = n;pos<len;pos++){
                for (int i=n-1;i<pos;i++){
                    arr2[pos] = min(arr2[pos], arr1[i]+getmax(0,len-1,0,i+1,pos));
                }
            }
            for (int i=0;i<len;i++){
                //cout <<arr2[i]<<" ";
                arr1[i] = arr2[i];
                arr2[i] = INT_MAX;
            }
            //cout <<endl;
        }
        return arr1[len-1];
    }
};