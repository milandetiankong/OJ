#include <cstdio>

#define MAX_LEN 10002
int buf[MAX_LEN];
int t[MAX_LEN];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int n, tmp;
	int a, b;
	scanf("%d", &n);
	tmp = 0;
	b = -1;
	for (int j=1; j<=n; j++) {
		scanf("%d", buf+j);
		if (b >= 0) {
			continue;
		}
		tmp = (tmp + buf[j]) % n;
		if (0 == tmp) {
			a = 0;
			b = j;
			continue;
		}
		if (t[tmp]) {
			a = t[tmp];
			b = j;
		} else {
			t[tmp] = j;
		}
	}
	printf("%d\n", b-a);
	for (int k=a+1; k<=b; k++) {
		printf("%d\n", buf[k]);
	}
	return 0;
}