#include <iostream>
using namespace std;

int buf[101];

int tmp[101];

int main(void) {
	for (int n=5; n<=100; ++n) {
		for (int i=1; i<=n; ++i) {
			buf[i] = 0;
		}
		for (int j=2; j<=n; ++j) {
			for (int k=j; k<=n; k+=j) {
				if(buf[k]) {
					buf[k] = 0;
				} else {
					buf[k] = 1;
				}
			}
		}
		int sum = 0;
		for (int i=1; i<=n; ++i) {
			if (buf[i]==0) {
				++sum;
			}
		}
		tmp[n] = sum;
	}
	int n, x;
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x;
		cout << tmp[x] << endl;
	}
	return 0;
}