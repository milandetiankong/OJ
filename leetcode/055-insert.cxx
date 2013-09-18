/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        int n = intervals.size();
        int i = 0;
        while (i < n && intervals[i].end < x.start) {
            ret.push_back(intervals[i++]);
        }
        Interval tmp = x;
        while (i < n && intervals[i].start <= x.end) {
            tmp.start = min(intervals[i].start, tmp.start);
            tmp.end = max(intervals[i].end, tmp.end);
            ++i;
        }
        ret.push_back(tmp);
        while (i < n) {
            ret.push_back(intervals[i++]);
        }
        return ret;
    }
};
