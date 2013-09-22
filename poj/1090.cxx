#include <cstdio>

int buf[1002];
int a[400];
int ans[500];

void multi(int *a, int b) {
	int len =a[0];
	long carry = 0;
	for (int j=1; j<=len; j++) {
		carry += a[j] * b;
		a[j] = carry % 10;
		carry /= 10;
	}
	if (carry) {
		a[++len] = carry;
	}
	a[0] = len;
}

void add(int *a, int *b) {
	int lena = a[0];
	int lenb = b[0];
	int maxab = lena>lenb ? lena: lenb;
	int carry = 0;
	for (int j=1; j<=maxab; j++) {
		carry += a[j] + b[j];
		a[j] = carry % 10;
		carry /= 10;
	}
	if (carry) {
		a[++maxab] = carry;
	}
	a[0] = maxab;
}


int main(int argc, const char * argv[])
{
	int n;
	scanf("%d", &n);
	for (int j=0; j<n; j++) {
		scanf("%d", buf+j);
	}
	for (int j=n-2; j>=0; j--) {
		buf[j] ^= buf[j+1];
	}
	a[0] = 1;
	a[1] = 1;
	for (int j=0; j<n; j++) {
		if (buf[j]) {
			add(ans, a);
		}
		multi(a, 2);
	}
	for (int j=ans[0]; j>=1; j--) {
		printf("%d", ans[j]);
	}
	if (0==ans[0]) {
		printf("0");
	}
	printf("\n");
	return 0;
}