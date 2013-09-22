class Solution {
    string x;
    char error(int a, int b) {
        int sum = 0;
        if (b - a >= 3) return 1;
        if (x[a] == '0') {
            if (a==b) return 0;
            else return 1;
        }
        for (int i = a; i <= b; ++i) {
            sum *= 10;
            sum += (x[i]-'0');
        } 
        if (sum <= 255) return 0;
        return 1;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        x = s;
        int n = s.size();
        vector<string> ret;
        for (int i = 0; i < n-1; ++i) {
            if (i >= 3) break;
            if (error(0, i)) continue;
            for (int j = i+1; j < n-1; ++j) {
                if (j-i > 3) break;
                if (error(i+1, j)) continue;
                for (int k = j+1; k < n-1; ++k) {
                    if (k-j > 3) break;
                    if (error(j+1, k)) continue;
                    if (error(k+1, n-1)) continue;
                    ret.push_back(string(s.begin(), s.begin()+i+1) + "."
                            + string(s.begin()+i+1, s.begin()+j+1) + "."
                            + string(s.begin()+j+1, s.begin()+k+1) + "."
                            + string(s.begin()+k+1, s.end()));
                }
            }
        }
        return ret;
    }
};
