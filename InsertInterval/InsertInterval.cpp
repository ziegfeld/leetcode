//============================================================================
// Given a set of non-overlapping intervals, insert a new interval into the
// intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their
// start times.
//
// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
// [1,2],[3,10],[12,16].
//
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
//
// Complexity:
// O(n)
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
public:
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        bool done = false;
        for (auto it : intervals) {
            if (it.end < newInterval.start) {
                res.push_back(it);
            }
            else if (newInterval.end < it.start) {
                if (!done) {
                    res.push_back(newInterval);
                    done = true;
                }
                res.push_back(it);
            }
            else {
                newInterval.start = min(newInterval.start, it.start);
                newInterval.end = max(newInterval.end, it.end);
            }
        }
        if (!done) res.push_back(newInterval);
        return res;
    }
};

int main() {
    return 0;
}
