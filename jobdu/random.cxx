#include <stdlib.h>
#include <time.h>
#include <iostream>


using namespace std;

int main(void) {
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        int j = rand() % 100;
        cout << j << endl;
        string s;
        int r;
        while (j) {
            r = rand() % 2;
            if (r) {
                s += '(';
            } else {
                s += ')';
            }
            --j;
        }
        cout << s << endl;
    }
    return 0;
}
