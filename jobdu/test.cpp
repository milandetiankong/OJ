#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[]) {
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
