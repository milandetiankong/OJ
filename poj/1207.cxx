#include <cstdio>

#define MAX_N 10000

int buf[MAX_N]={1,1};

int get(int n) {
	if (n >= MAX_N) {
		if (n%2) {
			return get(3*n+1) + 1;
		} else {
			return get(n/2) + 1;
		}
	}
	if (buf[n]) {
		return buf[n];
	}
	if (n%2) {
		buf[n] = get(n*3+1)+1;
	} else {
		buf[n] = get(n/2) + 1;
	}
	return buf[n];
}
int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int i, j;
	int a, b, max;
	for (int t=2; t<MAX_N; t++) {
		get(t);
	}	
	while (scanf("%d %d\n", &i, &j)!=EOF) {
		a = i<=j? i:j;
		b = i<=j? j:i;
		max = 0;
		for (int t=a; t<=b; t++) {
			if (max < buf[t]) {
				max = buf[t];
			}
		}
		printf("%d %d %d\n", i, j, max);
	}

	return 0;
}