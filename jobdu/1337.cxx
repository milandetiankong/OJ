#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

bool _gDebug;
#define _P(a)  if (_gDebug) cout << #a":" << a << " "
#define _P2(a, b)   if (_gDebug) cout << #a":" << a << " "#b":" << b << endl
#define _P3(a, b, c) if (_gDebug) {\
    cout << #a":" << a << " "#b":" << b << " "#c":" << c << endl;}

#define INF 1000006

int dp[INF];

int main(int argc, char *argv[]) {
    if (argc > 1) _gDebug = true;
    string s;
    int n;
    while (cin >> n >> s) {
        int max=0, mct=0;
        s = '*' + s;
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            if ('(' == s[i-1-dp[i-1]]) {
                dp[i] = dp[i-1] + 2;    
                dp[i] +=  dp[i-dp[i]];
            } else {
                dp[i] = 0;
            }
            if (dp[i] == max) ++mct;
            else if (dp[i] > max) {
                max = dp[i];
                mct = 1;
            }
        }
        if (max) {
            cout << max << " " << mct << endl;
        } else {
            cout << "0 1" << endl;
        }
    }
    return 0;
}

/* mark the used '(' or ')' to '+'
 *
 */
int main2(int argc, char *argv[]) {
    string s;
    int n;
    while (cin >> n >> s) {
        int max = 0, mct = 0, ct = 0;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if ('(' == s[i]) ++last;
            else if (last) {
                s[i] = '+';
                --last;
            }
        }

        last = 0;
        for (int i = n-1; i >= 0; --i) {
            if ('+' == s[i]) ++last;
            if ('('==s[i] && last) {
                s[i] = '+';
                --last;
            }
            if('+' == s[i]) {
                ++ct;
            } else {
                if (ct == max) { 
                    ++mct;
                } else if (ct > max) {
                    max = ct;
                    mct = 1;
                }
                ct = 0;
            }
        }

        if (ct == max) {
            ++mct;
        } else if (ct > max) {
            max = ct;
            mct = 1;
        }
        if (max) {
            cout << max << " " << mct << endl;
        } else {
            cout << "0 1" << endl;
        }
    }
    return 0;
}
