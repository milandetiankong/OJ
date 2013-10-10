/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &a, const Interval &b) {
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &is) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<Interval> ret;
        if (is.empty()) return ret;
        sort(is.begin(), is.end(), cmp);
        Interval tmp = is[0];
        for (int i = 1; i < is.size(); ++i) {
            if (is[i].start > tmp.end) {
                ret.push_back(tmp);
                tmp = is[i];
            } else if(is[i].end > tmp.end){
                tmp.end = is[i].end;
            }
        }
        ret.push_back(tmp);
        return ret;
    }
};
