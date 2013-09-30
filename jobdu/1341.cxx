#include <iostream>

using namespace std;

unsigned int dist[150];
char used[150];
unsigned int map[150][150];
const unsigned int maxInt = (unsigned int)(-1);

int N, M;
int begin, end;

void Dijkstra()
{
    for (int i = 1; i <= N; ++i) {
        dist[i] = map[i][begin];
        used[i] = 0;
    }
    used[begin] = 1;
    unsigned int min = -1;
   int j;
    while (1) {
        if (used[end]) break;
        min = maxInt;
        j = 0;
        for (int i = 1; i <= N; ++i) {
            if (used[i] == 0 && dist[i] < min) {
                j = i;
                min = dist[i];
            }
        }
        if (j < 1) break;
        used[j] = 1;
        for (int i = 1; i <= N; ++i) {
            if (used[i] == 0 && map[i][j] < maxInt) {
               min = dist[j] + map[i][j]; 
               if (dist[i] > min) {
                   dist[i] = min;
               }
            }
        }
    }
}

int main(void) {
    cin >> N >> M;
    cin >> end >> begin;

    int xx, yy, xy;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            map[i][j] = maxInt;
        }
        map[i][i] = 0;
    }
    for (int i = 0; i < M; ++i) {
        cin >> xx >> yy >> xy;
        if (map[xx][yy] > xy) map[xx][yy] = xy;
        map[yy][xx] = map[xx][yy];
    }
    Dijkstra();
    cout << dist[end] << endl;
    return 0;
}
