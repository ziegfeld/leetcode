//============================================================================
// Word Ladder II
// Given two words (start and end), and a dictionary, find all shortest 
// transformation sequence(s) from start to end, such that:
//
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
//
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// Return
//   [
//       ["hit","hot","dot","dog","cog"],
//       ["hit","hot","lot","log","cog"]
//   ]
// Note:
//  All words have the same length.
//  All words contain only lowercase alphabetic characters.
//============================================================================

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, vector<string> > from;
        unordered_set<string> visit;
        unordered_set<string> cq, nq;
        cq.insert(start);
        while (!cq.empty() && !cq.count(end)) {
            for (auto & cur : cq) visit.insert(cur);
            for (auto & cur : cq) {
                for (int i = 0; i < cur.size(); i++) {
                    auto next = cur;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (next[i] == c) continue;
                        next[i] = c;
                        if ((dict.count(next) || next == end) && !visit.count(next)) nq.insert(next), from[next].push_back(cur);
                    }
                }
            }
            swap(cq, nq);
            nq.clear();
        }
        vector<vector<string> > res;
        vector<string> path;
        getPath(end, start, from, path, res);
        return res;
    }

    void getPath(string & cur, string & start, unordered_map<string, vector<string> > & from, vector<string> & path, vector<vector<string> > & res) {
        path.push_back(cur);
        if (cur == start) res.push_back(vector<string>(path.rbegin(), path.rend()));
        else for (auto next : from[cur]) getPath(next, start, from, path, res);
        path.pop_back();
    }
};

int main() {
    Solution sol;
    {
        unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
        auto res = sol.findLadders("hit", "cog", dict);
        for (auto it1 : res) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }
    return 0;
}