#include <iostream>

using namespace std;

int n, m;
char x, tmp, y;

int buf[30][30];

char s[30];

int set (int a, int b) {
	if (buf[a][b]==-1) {
		return -1;
	} else if (buf[a][b]==0) {
		buf[a][b] = 1;
		buf[b][a] = -1;
		for (int i=0; i<n; ++i) {
			if(buf[i][a]==1) {
				buf[i][b] = 1;
				buf[b][i] = -1;
			}
		}

		for (int i=0; i<n; ++i) {
			if (buf[b][i]==1) {
				buf[a][i] = 1;
				buf[i][a] = -1;
			}
		}
	}
	return 0;
}

int check() {
	for (int j=0; j<n; ++j) {
		for (int k=0; k<n; ++k) {
			if (buf[j][k]==0 && j!=k) {
				return 0;
			}
		}
	}
	//sort ok
	return 1;
}

int main(void) {
	while (cin >> n >> m, m+n) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				buf[i][j] = 0;
			}
		}
		int ans = 0;
		for (int i=0; i<m; ++i) {
			cin >> x >> tmp >> y;
			x -= 'A';
			y -= 'A';

			if (ans==0) {//continue
				if(set(x, y)) {
					ans = -(i+1);
				} else {
					if(check()) {
						ans = i+1;
					}
				}
			}
		}
		if (ans==0) { // not sure
			cout << "Sorted sequence cannot be determined." << endl;
		} else if (ans<0) { // conflict
			cout << "Inconsistency found after " << -ans << " relations." << endl;
		} else { // sort ok
			cout << "Sorted sequence determined after " << ans 
				 << " relations: " << flush;
			for (int i=0; i<n; ++i) {
				int num=0;
				for (int j=0; j<n; ++j) {
					if (buf[i][j]==-1) {
						++num;	
					}
				}
				s[num] = i+'A';
			}
			s[n] = 0;
			cout << string(s) << flush;
			cout << "." << endl;
		}
	}
}