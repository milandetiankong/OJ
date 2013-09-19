#include <iostream>
#include <string>
#include <map>

using namespace std;

#define MAX 2005
int C[4][MAX];
int buf[301];
map<string, int> id2i;
int n, m;

int main(void) {
    int rk, tmp;
    cin >> n >> m;
    string id;
    for (int i = 0; i < n; ++i) {
        cin >> id;
        id2i[id] = i;
        cin >> C[0][i] >> C[1][i] >> C[2][i];
        C[3][i] = C[0][i] + C[1][i] + C[2][i];
    }

    for (int k = 0; k < 4; ++k) {
        for (int i = 300; i >= 0; --i) {
            buf[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            ++buf[C[k][i]];
        }
        rk = 1;
        for (int i = 300; i >= 0; --i) {
            if (buf[i]) {
                tmp = rk; 
                rk += buf[i];
                buf[i] = tmp;
            }
        }
        for (int i = 0; i < n; ++i) {
            C[k][i] = buf[C[k][i]];
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> id;
        if (id2i.find(id) == id2i.end()) {
            cout << "N/A" << endl;
        } else {
           char ch = 'A';
           int min = C[3][id2i[id]];
           if (C[0][id2i[id]] < min) {
               min = C[0][id2i[id]];
               ch = 'C';
           }
           if (C[1][id2i[id]] < min) {
               min = C[1][id2i[id]];
               ch = 'M';
           }
           if (C[2][id2i[id]] < min) {
               min = C[2][id2i[id]];
               ch = 'E';
           }
           cout << min << " " << ch << endl;
        }
    }
    return 0;
}
