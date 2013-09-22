#include <cstdio>
#include <cstring>


#define BIG_N  		160
#define BIG_BASE 	10

int result[BIG_N];

void print(int bits) {
	int i;
	if (result[0]==0) {
		printf("0\n");
		return;
	}
	if (bits >= result[0]) {
		putchar('.');
		while (bits > result[0]) {
			putchar('0');
			bits--;
		}
		while (bits > 0) {
			putchar(result[bits] + '0');
			bits--;
		}
	} else {
		while (result[0] > bits) {
			putchar(result[result[0]] + '0');
			result[0]--;
		}
		if (bits != 0) {
			putchar('.');
		}
		while (bits > 0) {
			putchar(result[bits] + '0');
			bits--;
		}
	}
	putchar('\n');
}
bool big_multi(int *result, int base) {
	long long carry=0;
	int i;

	for (i=1; i<BIG_N; i++) {
		carry = result[i]*base + carry;	
		result[i] = carry % BIG_BASE;
		carry = carry / BIG_BASE;
		result[0]--;
		if (result[0]<=0 && carry==0) {
			break;
		}
	}
	result[0] = i;
	if (BIG_N == i) {
		return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	//freopen("input.txt", "r", stdin);
	char buf[7];
	int n, base, bits, i, back;
	while (scanf("%s %d", buf, &n)!=EOF) {
		i=5;
		bits = 0;
		base = 0;
		memset(result, 0, sizeof(int)*BIG_N);
		while (buf[i] == '0') {	
			buf[i]=0;
			i--;
		}
		while (buf[i] != '.') {
			bits++;
			i--;
		}
		bits *= n;
		for (i=0; buf[i]; i++) {
			if (buf[i] == '.') {
				continue;
			}
			base *= 10;
			base += buf[i]-'0';
		}
		back = base;
		i=1;

		while (back) {
			result[i++] = back % BIG_BASE;
			back /= BIG_BASE;
		}
		result[0] = i-1;
		if (0 == n){
			result[0]=0;
		} else {
			while (--n){
				big_multi(result, base);
			}
		}
		print(bits);
	}
	return 0;
}