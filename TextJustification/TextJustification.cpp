//============================================================================
// Text Justification
// Given an array of words and a length L, format the text such that each line
// has exactly L characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words
// as you can in each line. Pad extra spaces ' ' when necessary so that each
// line has exactly L characters.
//
// Extra spaces between words should be distributed as evenly as possible. If
// the number of spaces on a line do not divide evenly between words, the empty
// slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is
// inserted between words.
//
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
//
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.
//
// Corner Cases:
// A line other than the last line might contain only one word. What should
// you do in this case?
// In this case, that line should be left-justified.
//
// Complexity:
// O(n) time
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int begin = 0, end = 0;
        while (end < words.size()) {
            int len = L;
            for (; end < words.size(); end++) {
                int tmp = len - (len == L ? words[end].size() : words[end].size() + 1);
                if (tmp < 0) break;
                len = tmp;
            }
            ostringstream os;
            int num = end - begin - 1;
            if (num != 0 && end != words.size()) {
                int avg = len / num;
                len %= num;
                for (; begin < end; begin++) {
                    if (begin == end - 1) os << words[begin];
                    else os << words[begin] << string(avg + 1, ' ');
                    if (len > 0) os << ' ', len--;
                }
            }
            else {
                for (; begin < end; begin++) {
                    if (begin == end - 1) os << words[begin];
                    else os << words[begin] << ' ';
                }
                if (len > 0) os << string(len, ' ');
            }
            res.push_back(os.str());
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> p0;
    int p1;

    {
        p0 = { "This", "is", "an", "example", "of", "text", "justification." };
        p1 = 16;
        auto p2 = sol.fullJustify(p0, p1);
        for (auto it : p2) cout << "[" << it << "]" << endl;
    }

    {
        p0 = { "What", "must", "be", "shall", "be." };
        p1 = 12;
        auto p2 = sol.fullJustify(p0, p1);
        for (auto it : p2) cout << "[" << it << "]" << endl;
    }

    return 0;
}