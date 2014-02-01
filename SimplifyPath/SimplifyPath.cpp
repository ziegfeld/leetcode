//============================================================================
// SimplifyPath
// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together,
// such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".
//
// Vector based, O(n) time, O(n) space
// In-Place, O(n) time, O(1) space
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        return simplifyPath2(path);
    }

    string simplifyPath1(string & path) {
        replace(begin(path), end(path), '/', ' ');
        vector<string> vs;
        istringstream is(path);
        string str;
        while (is >> str) {
            if (str == "..") {
                if (!vs.empty()) vs.pop_back();
                continue;
            }
            if (str != ".") vs.push_back(str);
        }
        if (vs.empty()) return "/";
        string res;
        for (auto s : vs) res += ('/' + s);
        return res;
    }

    string simplifyPath2(string & path) {
        if (path.empty()) return path;
        if (path.back() != '/') path.push_back('/');
        int last = 0;
        for (int start = 0, end = 0; end < path.size(); end++) {
            if (path[end] != '/') continue;
            if (end - start == 3 && path[end - 1] == '.' && path[end - 2] == '.') {
                while (last > 0 && path[--last] != '/');
            }
            else if (end - start > 2 || (end - start == 2 && path[end - 1] != '.')) {
                while (start < end) path[last++] = path[start++];
            }
            start = end;
        }

        if (last == 0) return "/";
        return path.substr(0, last);
    }
};

int main() {
    return 0;
}
