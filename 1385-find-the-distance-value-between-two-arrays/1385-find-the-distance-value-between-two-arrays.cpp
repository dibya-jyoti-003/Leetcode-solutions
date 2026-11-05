class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for (int i: arr1)ans += (upper_bound(arr2.begin(), arr2.end(), i+d) == lower_bound(arr2.begin(), arr2.end(), i-d));
        return ans;
    }
};