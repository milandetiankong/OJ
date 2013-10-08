#include <iostream>

using namespace std;

int buf[400][400];
int n, k, a, b, d;

int main(void) {
    int tmp;
    while (cin >> n) {
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> buf[i][j];
                sum += buf[i][j];
            }
        }
        sum /= 2;
        cin >> k;
        for (int ki = 0; ki < k; ++ki) {
            cin >> a >> b >> d;
            if (buf[a][b] > d) {
                buf[a][b] = d;
                buf[b][a] = d;
                sum  = 0;
                for (int i = 1; i <= n; ++i) {
                    for (int j = i+1; j <= n; ++j) {
                        tmp = d + buf[i][a] + buf[b][j];
                        if (tmp < buf[i][j]) {
                            buf[i][j] = tmp;
                        }
                        tmp = d + buf[i][b] + buf[a][j];
                        if (tmp < buf[i][j]) {
                            buf[i][j] = tmp;
                        }
                        buf[j][i] = buf[i][j];
                        sum += buf[i][j];
                    }
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}
