//============================================================================
// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1, find the area of largest rectangle in the
// histogram.
//
// For example,
// Given height = [2,1,5,6,2,3],
// return 10.
// 
// Complexity:
// Binary search + Range Min Query O(nlog(n))
// Sorted Stack O(n)
//============================================================================

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        return largestRectangleArea2(height);
    }

    int largestRectangleArea1(vector<int> &height) {
        if (height.empty()) return 0;
        height.push_back(0);
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[stk.top()] >= height[i]) {
                int h = height[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, h*w);
            }
            stk.push(i);
        }
        return res;
    }

    int largestRectangleArea2(vector<int> &height) {
        int N = height.size();
        vector<int> vs(4 * N, 0);
        build(height, vs, 1, 0, N - 1);
        return largestRectangleAreaHelper(height, vs, 0, N - 1);
    }

    int largestRectangleAreaHelper(vector<int> & hs, vector<int> & vs, int l, int r) {
        if (l > r) return -1;
        if (l == r) return hs[l];
        int m = query(hs, vs, 1, 0, hs.size() - 1, l, r);
        int res = (r - l + 1)*hs[m];
        res = max(res, largestRectangleAreaHelper(hs, vs, l, m - 1));
        res = max(res, largestRectangleAreaHelper(hs, vs, m + 1, r));
        return res;
    }

    void build(vector<int> & hs, vector<int> & vs, int n, int s, int e) {
        if (s == e) {
            vs[n] = s;
            return;
        }
        int l = 2 * n, r = 2 * n + 1, m = s + (e - s) / 2;
        build(hs, vs, l, s, m);
        build(hs, vs, r, m + 1, e);
        if (hs[vs[l]] <= hs[vs[r]]) vs[n] = vs[l];
        else vs[n] = vs[r];
    }

    int query(vector<int> & hs, vector<int> & vs, int n, int s, int e, int i, int j) {
        if (i > e || j < s) return -1;
        if (i <= s && e <= j) return vs[n];
        int l = 2 * n, r = 2 * n + 1, m = s + (e - s) / 2;
        int q1 = query(hs, vs, l, s, m, i, j);
        int q2 = query(hs, vs, r, m + 1, e, i, j);
        if (q1 == -1) return vs[n] = q2;
        if (q2 == -1) return vs[n] = q1;
        if (hs[q1] <= hs[q2]) return vs[n] = q1;
        return vs[n] = q2;
    }
};

int main() {
    Solution sol;
    vector<int> p0;

    {
        int a[] = { 2, 1, 5, 6, 2, 3 };
        p0.assign(begin(a), end(a));
        cout << sol.largestRectangleArea(p0) << endl;
    }

    return 0;
}
