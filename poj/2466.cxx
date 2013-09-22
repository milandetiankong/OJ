#include <cstdio>

int buf[60];
bool map[60];
int result[12];


int n, nn;

int find_litte(bool * m) {

	int i = 0;
	int nni = 0;

	while (m[nni++]) ;

	for (i=nni-1; nni<nn; nni++) {
		if (m[nni] == false && buf[nni] < buf[i]) {
			i = nni;
		}
	}

	m[i] = true;
	
	return i;
}


bool set_true(int aix, bool * m) {
	for (int nni=0; nni<nn; nni++) {
		if (m[nni]==false && buf[nni]==aix) {
			m[nni] = true;
			return true;
		}
	}
	return false;
}

bool test(int a12i, int a13i, int k) {
	int double_a1 = buf[a12i] + buf[a13i] - buf[k]; 	
	if (double_a1&1) {
		return false;
	}
	result[0] = double_a1/2;
	result[1] = buf[a12i] - result[0];
	result[2] = buf[a13i] - result[0];
	bool tmp[60];

	for (int j=0; j<nn; j++) {
		tmp[j] = false;
	}
	tmp[a12i] = true;
	tmp[a13i] = true;
	tmp[k] = true;

	for (int x=3; x<n; x++) {
		int a1xi = find_litte(tmp);
		
		result[x] = buf[a1xi] - result[0];
		for (int i=1; i<x; i++) {
			int aix = result[i] + result[x];	
			if (set_true(aix, tmp)==false) {
				return false;
			}
		}
	}	
	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		nn = n*(n-1)/2;
		for (int nni=0; nni<nn; nni++) {
			scanf("%d", buf+nni);
			map[nni] = false;
		}
		int a12i = find_litte(map);
		int a13i=  find_litte(map);


		bool is_ok = false;
		for (int nni=0; nni<nn && !is_ok; nni++) {
			if (map[nni]==false) {
				is_ok = test(a12i, a13i, nni);
			}
		}
		if (!is_ok) {	
			printf("Impossible\n");
			continue;
		}
		int i = 0;
		printf("%d", result[i]);
		for (i=1; i<n; i++) {
			printf(" %d", result[i]);
		}
		printf("\n");
	}

}