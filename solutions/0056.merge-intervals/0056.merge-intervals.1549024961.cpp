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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        });
        vector<Interval> res;
        int i = 0;
        while (i < intervals.size()) {
            int j = i + 1;
            int R = intervals[i].end;
            while (j < intervals.size() && intervals[j].start <= R) {
                R = max(R, intervals[j].end);
                j++;
            }
            // Intervals[i..j) overlaps
            Interval in(intervals[i].start, R);
            res.push_back(in);
            i = j;
        }
        return res;
    }
};
