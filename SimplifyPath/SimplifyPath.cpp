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

    string simplifyPath(string path) {
        if (path.empty()) return "/";
        replace(begin(path), end(path), '/', ' ');
        vector<string> vs;
        istringstream is(path);
        string str;
        while (is >> str) {
            if (str == "..") { if (!vs.empty()) vs.pop_back(); }
            else { if (str != ".") vs.push_back(str); }
        }
        if (vs.empty()) return "/";
        ostringstream os;
        for (auto v : vs) os << "/" << v;
        return os.str();
    }

    string simplifyPath2(string & path) {
        if (path.empty()) return "/";
        if (path.back() != '/') path.push_back('/');
        int len = 0;
        for (int begin = 0, end = 0; end < path.size(); end++) {
            if (path[end] != '/') continue;
            if (end - begin == 3 && path[end - 2] == '.' && path[end - 1] == '.') {
                if (len > 0) len--;
                while (len > 0 && path[len] != '/') len--;
            }
            else if (end - begin > 2 || (end - begin == 2 && path[end - 1] != '.')) {
                while (begin < end) path[len++] = path[begin++];
            }
            begin = end;
        }
        return len == 0 ? "/" : path.substr(0, len);
    }
};

int main() {
    return 0;
}
