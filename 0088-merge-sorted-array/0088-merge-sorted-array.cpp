class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, pos=n+m-1;
        while (i>=0 and j>=0){
            if (nums1[i] >= nums2[j]) nums1[pos] = nums1[i--];
            else nums1[pos] = nums2[j--];
            pos--;
        }
        while (j>=0){
            nums1[j] = nums2[j];
            j--;
        }
    }
};