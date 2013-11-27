//============================================================================
// Max Points on a Line 
//
// Given n points on a 2D plane, find the maximum number of points that lie 
// on the same straight line.
//
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
* Definition for a point.
**/

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int hashPoint(Point & p) { return (51+p.x)*51+p.y; }

struct Line {
    int a;
    int b;
    int c;
    Line(int x, int y, int z) {
        int d = gcd(max(abs(x), abs(y)), min(abs(x), abs(y)));
        d = gcd(max(abs(z), d), min(abs(z), d));
        if (x < 0) d *= -1;
        a = x/d;
        b = y/d;
        c = z/d;
    };

    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x%y);
    }
};

int hashLine(Line & l) { return ((51+l.a)*51+l.b)*51+l.c; }

class Solution {
public:
    int maxPoints(vector<Point> & ps) {
        int N = ps.size();
        if (N <= 2) return N;

        int res = 0;
        unordered_map<int, int> pt;
        for (int i = 0; i < N; i++) {
            int h = hashPoint(ps[i]);
            pt[h] += 1;
            if (pt[h] > res) res = pt[h];
        }

        unordered_map<int, unordered_set<int> > lt;
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                int a = ps[j].y-ps[i].y;
                int b = ps[i].x-ps[j].x;
                if (a == 0 && b == 0) continue;
                int c = -a*ps[i].x-b*ps[i].y;
                Line l(a, b, c);
                int h = hashLine(l);
                lt[h].insert(i);
                lt[h].insert(j);
                if ((int)lt[h].size() > res) res = lt[h].size();
            }
        }

        return res;
    }
};

int main() {
    return 0;
}