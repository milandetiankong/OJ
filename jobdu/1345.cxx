#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int f(int i) {
    if (i == 1) return 1;
    return f(i-1)*3;
}

void draw(int i, int j, int k, vector<string> & ret) {
    if (k == 0) {
        ret[i][j] = 'X';
        return;
    }
    draw(i, j, k/3, ret);
    draw(i-k, j-k, k/3, ret);
    draw(i-k, j+k, k/3, ret);
    draw(i+k, j-k, k/3, ret);
    draw(i+k, j+k, k/3, ret);
}

int main(void) {
    int n;
    while (cin >> n) {
        if (n <= 0) break;
        int m = f(n);
        vector<string> ret(m, string(m, ' '));
        draw(m/2, m/2, m/3, ret);
        for (int i = 0; i < ret.size(); ++i) {
            cout << ret[i] << endl;
        }
        cout << "#" << endl;
    }
    return 0;
}

