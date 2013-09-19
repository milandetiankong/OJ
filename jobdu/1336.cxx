#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
bool _gDebug;
#define _P(a)  if (_gDebug) cout << #a":" << a << " "
#define _P2(a, b)   if (_gDebug) cout << #a":" << a << " "#b":" << b << endl
#define _P3(a, b, c) if (_gDebug) {\
    cout << #a":" << a << " "#b":" << b << " "#c":" << c << endl;}

#define INF 100000

int gcd(int x, int y) {
    int tmp;
    while (y) {
       tmp = x % y;
       x = y;
       y = tmp;
    }
    return x;
}

int main(int argc, char *argv[]) {
    if (argc > 1) _gDebug = true;
    ll a, b, x, y;
    while (cin >> a >> b >> x >> y) {
        int xy = gcd(x, y);
        x /= xy;
        y /= xy;
        if (b*x >= a*y) {
            xy = a/x;
            cout << x*xy << " " << y*xy << endl;
        } else {
            xy = b/y;
            cout << x*xy << " " << y*xy << endl;
        }
    }

    return 0;
}
