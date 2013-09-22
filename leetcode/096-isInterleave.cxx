class Solution {
    string a1, a2, a3;
    int n1, n2, n3;
public:
    bool dfs(int x, int y, int z) {
        if (x == n1 && y == n2) return true;
        if (x == n1) {
            return ! a3.compare(z, n3-z, a2, y, n2-y);
        }
        if (y == n2) {
            return ! a3.compare(z, n3-z, a1, x, n1-x);
        }
        while (z < n3) {
            if (a1[x] == a2[y]) {
                if (a1[x] == a3[z]) return dfs(x+1, y, z+1) || dfs(x, y+1, z+1);
                else return false;
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
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        a1 = s1; a2 = s2; a3 = s3;
        n1 = s1.size(); n2 = s2.size(); n3 = s3.size();
        if (n1+n2 != n3) return false;
        return dfs(0, 0, 0);
    }
};
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1+n2 != n3) return false;
        vector<vector<char> > dp(n1+1, vector<char>(n2+1, 1));
        for (int i = 1; i <= n2; ++i) {
            dp[0][i] = dp[0][i-1] && (s2[i-1] == s3[i-1]);
        }

        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
            for (int j = 1; j <= n2; ++j) { 
                dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
                dp[i][j] = dp[i][j] || dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
            }
        }
        return dp[n1][n2];
    }
};
