#include <cstdio>
int f[1000];

int main(void) {
	int n;
	f[0]=2;
	scanf("%d", &n);
	int sum = n-2;
	int i;
	for (i=1; sum >f[i-1]; ++i) {
		f[i] = f[i-1] + 1;
		sum -= f[i];
	}
	--i;
	for (int j=i; sum>0 && j>=0; --j) {
		--sum;
		++f[j];
	}
	for (int j=i; sum>0 && j>=0; --j) {
		--sum;
		++f[j];
	}
	for (int j=0; j<i; ++j) {
		printf("%d ", f[j]);
	}
	printf("%d\n", f[i]);
}