//============================================================================
// Implement strStr().
//
// Returns a pointer to the first occurrence of needle in haystack,
// or null if needle is not part of haystack.
//
// Complexity:
// brute force, O(n*m) time, O(1) space
// Knuth-Morris-Pratt Algorithm (KMP), O(n+m) time, O(n) space
//============================================================================

#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    char * strStr(char * haystack, char * needle) {
        return strStr3(haystack, needle);
    }


    char *strStr1(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL) return NULL;
        int n = strlen(haystack), m = strlen(needle);
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) j++;
            if (j == m) return haystack + i;
        }
        return NULL;
    }

    char *strStr2(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL) return NULL;
        int m = strlen(needle);
        if (m == 0) return haystack;
        vector<int> fs(m + 1, 0);
        for (int i = 2; i <= m; i++) {
            int j = fs[i - 1];
            while (true) {
                if (needle[j] == needle[i - 1]) { fs[i] = j + 1; break; }
                if (j == 0) { break; }
                j = fs[j];
            }
        }
        int n = strlen(haystack), i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++, j++;
                if (j == m) return haystack + i - m;
            }
            else if (j > 0) j = fs[j];
            else i++;
        }
        return NULL;
    }
};

int main() {
    return 0;
}
