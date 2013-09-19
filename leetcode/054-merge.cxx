/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool _cmp(const Interval & a, const Interval &b) {
     if (a.start == b.start) return a.end < b.end;
     return a.start < b.start;
 }
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), _cmp);

        Interval tmp;
        vector<Interval> ret;
        if (intervals.size() == 0) return ret;
        tmp = intervals[0];
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= tmp.end) {
                if (tmp.end < intervals[i].end) tmp.end = intervals[i].end;
            } else {
                ret.push_back(tmp);
                tmp = intervals[i];
            }
        }
        ret.push_back(tmp);
        return ret;
    }
};
