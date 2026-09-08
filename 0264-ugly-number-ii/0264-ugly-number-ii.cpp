#define ll long long
class Solution {

public:
    int nthUglyNumber(int n) {
        set<ll> my_set;
        int cnt = 0;
        my_set.insert(1);
        while(!my_set.empty()){
            ll top = *my_set.begin();
            my_set.erase(top);
            cnt++;
            cout <<cnt<<"-> "<<top<<endl;
            if (cnt == n)return top;
            my_set.insert(top*2);
            my_set.insert(top*3);
            my_set.insert(top*5);
        }
        return 0;
    }
};