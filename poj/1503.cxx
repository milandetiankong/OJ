#include <cstdio>
#include <cstring>

char buf[102];
char s[101];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	while (gets(s), strcmp(s,"0")) {
		int len = strlen(s);
		int i, j;

		for (i=len-1, j=0; i>=0; i--) {
			buf[j] += s[i] - '0';
			if (buf[j++] > 9) {
				buf[j-1] %= 10;
				++buf[j];
			}
		}
		while (buf[j] > 9) {
			buf[j] %= 10;
			++buf[++j];
		}

	}	
	int j=101;
	while (buf[j]==0) {
		j--;
	}
	if (j < 0) {
		putchar('0');
	}
	while (j>=0) {
		putchar(buf[j--] + '0');
	}
	putchar('\n');
	return 0;
}