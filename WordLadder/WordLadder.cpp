//============================================================================
// Word Ladder
// Given two words (start and end), and a dictionary, find the length of 
// shortest transformation sequence from start to end, such that:
//
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
//
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//============================================================================

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> & dict) {
        queue<pair<string, int> > queue;
        queue.push(make_pair(start, 1));
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            if (cur.first == end) return cur.second;

            for (int i = 0; i < (int)cur.first.size(); i++) {
                string copy = cur.first;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == copy[i]) continue;
                    copy[i] = c;
                    if (dict.find(copy) == dict.end() && copy != end) continue;
                    queue.push(make_pair(copy, cur.second+1));
                    dict.erase(copy);
                }
            }
        }

        return 0;
    }
};

int main() {
    return 0;
}