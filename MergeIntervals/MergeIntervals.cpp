//============================================================================
// Given a collection of intervals, merge all overlapping intervals.
//
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].
//
// Complexity:
// O(nlog(n))
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* Definition for an interval.
*/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        sort(begin(intervals), end(intervals),
            [] (const Interval & a, const Interval & b) {
                return a.start < b.start;
        });

        auto pre = intervals[0];
        for (int i = 1; i < (int)intervals.size(); i++) {
            auto cur = intervals[i];
            if (pre.end < cur.start) {
                res.push_back(pre);
                pre = cur;
            }
            else {
                pre.start = min(pre.start, cur.start);
                pre.end = max(pre.end, cur.end);
            }
        }
        res.push_back(pre);
        return res;
    }
};

int main() {
    Solution sol;
    vector<Interval> p0;

    {
        Interval a[] = { Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18) };
        p0.assign(begin(a), end(a));
        auto p1 = sol.merge(p0);
        for (auto it : p1) cout << it.start << "," << it.end << endl;
    }

    return 0;
}
