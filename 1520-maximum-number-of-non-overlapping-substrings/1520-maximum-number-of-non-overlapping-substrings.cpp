#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
class Solution {
public:
    vs maxNumOfSubstrings(string s) {
        int n = s.size();
        vi first(26, n),last(26, -1) ;
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            if (first[ch] == n) first[ch] = i;
            last[ch] = i;
        }
        vvi intervals;
        for (int ch = 0; ch < 26; ch++) {
            if (last[ch] == -1)continue;
            int start = first[ch];
            int end = last[ch];
            bool valid = true;
            for (int i = start; i <= end; i++) {
                int current = s[i] - 'a';
                if (first[current] < start) {
                    valid = false;
                    break;
                }
                end = max(end, last[current]);
            }
            if (valid)intervals.push_back({start, end});
        }
        sort(intervals.begin(), intervals.end(),[](const vi& a, const vi& b) {
                if (a[1] != b[1]) return a[1] < b[1];
                return (a[1] - a[0]) < (b[1] - b[0]);
            });
        vs answer;
        int previousEnd = -1;
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if (start > previousEnd) {
                answer.push_back(s.substr(start, end - start + 1));
                previousEnd = end;
            }
        }
        return answer;
    }
};