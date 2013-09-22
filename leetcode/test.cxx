#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    string a1, a2, a3;
    int n1, n2, n3;
public:
    bool dfs(int x, int y, int z) {
        cout << x << " " << y << " " << z << endl;
        if (x == n1 && y == n2) return true;
        if (x == n1) {
            return ! a3.compare(z, n3-z, a2, y, n2-y);
        }
        if (y == n2) {
            return ! a3.compare(z, n3-z, a1, x, n1-x);
        }
        while (z < n3) {
            if (a1[x] == a2[y]) {
                if (a1[x] == a3[z]) {
                    if (dfs(x+1, y, z+1)) return true;
                    else ++y;
                } else return false;
            } else if (a1[x] == a3[z]) {
                ++x;
            } else if (a2[y] == a3[z]) {
                ++y;
            } else {
                return false;
            }
            ++z;
            if (x==n1 || y==n2) return dfs(x, y, z);
        }
        return true;
    }
    bool abc(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        a1 = s1; a2 = s2; a3 = s3;
        n1 = s1.size(); n2 = s2.size(); n3 = s3.size();
        if (n1+n2 != n3) return false;
        return dfs(0, 0, 0);
    }
};
int main(void) {
    Solution sl;
    int x[] = {1, 1, 1, 3, 1};
    vector<int> in(1, 1);
    /*
const char * a = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbab"\
"abbbbbabbbbababbabaabababbbaabababababbbaaababaa";
const char * b = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaab"\
"aaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
const char * c = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbb"\
"aaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbab"\
"abbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaa"\
"abbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
*/
    const char * a = "aaaaaaaaaaa";
    const char * b = "aaaaaaaaaaa";
    const char * c = "aaaaaaaaaaaaaaaaaaaaaa";

    //string minWindow(string S, string T) {
    sl.abc(a, b, c);
    return 0;
}
