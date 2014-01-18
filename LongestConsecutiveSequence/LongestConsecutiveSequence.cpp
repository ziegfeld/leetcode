//============================================================================
// Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest 
// consecutive elements sequence.
//
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its 
// length: 4.
//
// Your algorithm should run in O(n) complexity.
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty()) return 0;
        return longestConsecutive1(num);
    }

    int longestConsecutive1(vector<int> &num) {
        sort(begin(num), end(num));
        int res = 1, cnt = 1;
        for (int i = 1; i < (int)num.size(); i++) {
            if (num[i-1] == num[i]) continue;
            if (num[i-1]+1 == num[i]) cnt++;
            else cnt = 1;
            res = max(res, cnt);
        }
        return res;
    }

    int longestConsecutive2(vector<int> &num) {
        unordered_map<int, int> tb;
        int res = 1;
        for (int n : num) {
            if (tb.find(n) != tb.end()) continue;
            tb[n] = 1;
            if (tb.find(n-1) != tb.end()) res = max(res, merge(tb, n-1, n)); 
            if (tb.find(n+1) != tb.end()) res = max(res, merge(tb, n, n+1));
        }
        return res;
    }

    int merge(unordered_map<int, int> & tb, int l, int r) {
        int lo = l-tb[l]+1;
        int hi = r+tb[r]-1;
        return tb[lo] = tb[hi] = hi-lo+1;
    }
};

int main() {
    vector<int> p0;

    Solution sol;
    {
        int a[] = {100, 4, 200, 1, 3, 2};
        p0.assign(begin(a), end(a));
        cout << sol.longestConsecutive(p0) << endl;
    }
    return 0;
}